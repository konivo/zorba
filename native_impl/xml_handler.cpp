/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_handler.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "xml_handler.h"

#include <iostream>
#include <string>

#include "../values/qname_value.h"
#include "../util/xqp_exception.h"
#include "../util/tokenbuf.h"
#include "../util/URI.h"


using namespace std;
namespace xqp {

#define DELIMSET " \n,.;:?!\r\t+-_!@#$%&*()[]{}=/|\\<>'\""

xml_handler::xml_handler(
	uint64_t _uri,
	vector<xml_term>& _term_v,
	rchandle<nodestore> _nstore_h,
	context * _ctx_p)
:
	scan_handler(),
	top(0),
	nid_top(0),
	the_attribute(""),
	the_element(""),
	the_PCDATA(""),
	the_PITarget(""),
	the_entity(0),
	term_pos(0),
	last_pos(0),
	uri(_uri),
	term_v(_term_v),
	attr_v(8),
	nstore_h(_nstore_h),
	ctx_p(_ctx_p),
	nodeid(0),
	parentid(0),
	docid(0)
{
}


xml_handler::xml_handler(
	string const&  _uri,
	vector<xml_term>& _term_v,
	rchandle<nodestore> _nstore_h,
	context * _ctx_p)
:
	scan_handler(),
	top(0),
	nid_top(0),
	the_attribute(""),
	the_element(""),
	the_PCDATA(""),
	the_PITarget(""),
	the_entity(0),
	term_pos(0),
	last_pos(0),
	uri(URI(_uri).hashkey()),
	term_v(_term_v),
	attr_v(8),
	nstore_h(_nstore_h),
	ctx_p(_ctx_p),
	nodeid(0),
	parentid(0),
	docid(0)
{
}


void xml_handler::error(
	string const& msg) const
throw (xqp_exception)
{
	throw xqp_exception("XML_HANDLER", msg);
}


inline void xml_handler::add_term(
	xml_term const& term)
{
	term_v.push_back(term);
}


// attribute without value callback
void xml_handler::adup(const char* buf, int offset, int length)
{
	if (length==0) return;
	the_attribute = string(buf,offset,length);
	string prefix("");
	string name("");
	string::size_type loc = the_attribute.find(':', 0);
	if (loc!=string::npos) {
		prefix = the_attribute.substr(0,loc);
		name = the_attribute.substr(loc+1);
	}
	else {
		name = the_attribute;
	}
	nstore_p->put(ctx_p, new QName(QName::qn_attr,prefix,name));
}


// attribute name callback
void xml_handler::aname(const char* buf, int offset, int length)
{
	if (length==0) return;
	the_attribute = string(buf,offset,length);
}


// attribute value callback
void xml_handler::aval(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << "@" << the_attribute << "=" << string(buf,offset,length) << endl;
#endif
	if (length==0) return;
	const char* p = &buf[offset];

	tokenbuf tokbuf(p,0,length,DELIMSET);
	tokbuf.set_lowercase();

	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();

	for (; it!=end; ++it) {
		const string& term = *it;
		if (term.length()==0) continue;
		string attr_term = '@'+the_attribute+"/word::"+term;
		add_term(xml_term(attr_term,uri,term_pos++));
		string elem_attr_term = the_element+"/@"+the_attribute+"/word::"+term;
		add_term(xml_term(elem_attr_term,uri,term_pos++));
	}
	
	nstore_p->put(ctx, new attribute_node());
}


// &ent; entity callback
void xml_handler::entity(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << '&' << string(buf,offset,length) << ';' << endl;
#endif
	string s(buf,offset,length);
	unsigned short code;
  entityMap.get(s, code);
	if (code==0) return;
	ent = (char)code;
}


// eof callback
void xml_handler::eof(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << "===== eof =====" << endl;
#endif
}


#define NAME  first
#define VALUE second

// end tag callback
void xml_handler::etag(const char* buf, int offset, int length)
{
	if (length==0) return;
	string tag(buf,offset,length);

#ifdef DEBUG
	cout << "</" << tag << ">" << endl;
	for (uint32_t k=0; k<top; ++k) {
		cout << "stack["<<k<<"] = "<<the_stack[k]<<endl;
	}
#endif

	int k = top;
	while (k>0) {
		string tag0 = the_stack[--k];
		size_t a = tag0.find(' ');
		if (a!=string::npos) tag0 = tag0.substr(0,a);
		if (tag0==tag) break;
	}
	if (k==0) return;
	top = k;
	
	// serialize
	xos << QName(QName::qn_elem,the_element);

	attrpair_it_t it = attr_v.begin();
	for (; it!=attr_v.end(); ++it) {
  	attrpair_t p = *it;
  	xos << QName(QName::qn_attr,p.NAME);
  	xos << p.VALUE;
	}
}


// general identifier = tag callback
void xml_handler::gi(const char* buf, int offset, int length)
{
	if (length==0) return;
	the_element = string(buf,offset,length);
	if (top>=STACK_CAPACITY) error("stack overflow");

	the_stack[top++] = the_element;
	nodeid_stack[nid_top++] = nodeid;
	nodeid = ctx_p->get_nodeid(); 

	string prefix;
	string name;
	string::size_type loc = the_element.find(':', 0);
	if (loc!=string::npos) {
		prefix = the_element.substr(0,loc);
		name = the_element.substr(loc+1);
	}
	else {
		name = the_attribute;
	}
	nstore_p->put(ELEM_CODE);
	nstore_p->put(ctx_p,docid); 
	nstore_p->put(ctx_p,nodeid); 
	nstore_p->put(ctx_p,parentid); 
	qnameid = qnpool_h->put(new QName(QName::elem,prefix,name));
	nstore_p->put(ctx_p,qnameid);
	nstore_p->put(ctx_p,nsid);

#ifdef DEBUG
	cout <<'<'<<the_element<<"> ";
#endif

}


// parsed content (tag body) callback
void xml_handler::pcdata(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << "pcdata = " << string(buf,offset,length) << endl;
#endif
	if (length==0) return;
	bool allWhite = true;
	for (int i=0; i<length; ++i) {
		if (!isspace(buf[offset+i])) { allWhite = false; break; }
	}
	if (allWhite) return;
	handle_pcdata(buf, offset, length);
}


void xml_handler::add_term(
	string const& term,
	uint64_t uri,
	uint32_t pos)
{
	string e;			// element node
	string p;			// parent node
	string gp;		// grandparent node
	string ggp;		// great-grandparent

	if (term_indexing) {
		add_term(xml_term(term, uri, pos));
	}
	if (top>=1) {
		e = the_stack[top-1];
		e += "/word::"+term;
		if (e_indexing) add_term(xml_term(e, uri, pos));
	}
	if (top>=2) {
		p = the_stack[top-2];
		p += "/child::"+e;
		if (p_indexing) add_term(xml_term(p, uri, pos));
	}
	if (top>=3) {
		string gp = the_stack[top-3];
		gp += "/child::"+p;
		if (gp_indexing) add_term(xml_term(gp, uri, pos));
	}
	if (top>=4) {
		ggp = the_stack[top-4];
		ggp += "/child::"+gp;
		if (ggp_indexing) add_term(xml_term(ggp, uri, pos));
	}
}


void xml_handler::handle_pcdata(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << "handle_pcata = |" << string(buf,offset,length)
			 << "| [" << length << "]\n";
#endif

	tokenbuf tokbuf(buf,offset,length,DELIMSET);
	tokbuf.set_lowercase(true);
	string last("");

	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();

#ifdef DEBUG
	cout << "it.get_token_pos() = " << it.get_token_pos() << endl;
	cout << "end.get_token_pos() = " << end.get_token_pos() << endl;
#endif

	for (;it!=end; ++it) {
		string const& term = *it;
#ifdef DEBUG
		cout << "handle_pcdata::term = " << term << endl;
		cout << "it.get_token_pos() = " << it.get_token_pos() << endl;
#endif
		if (term.length()==0) continue;

		add_term(term, uri, term_pos);

		if (bigram_indexing && last_pos>0) {
			string bigram = last+"#"+term;
			add_term(bigram, uri, last_pos);
		}

		last_pos = term_pos;
		last = term;
		++term_pos;
	}
	
	xos << string(buf,offset,length);
}



// processing instruction callback
void xml_handler::pi(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << "<?" << s << endl;
#endif
}


// processing instruction target callback
void xml_handler::pitarget(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << " " << s << ">" << endl;
#endif
}


// start tag close (attributes all processed) callback 
void xml_handler::stagc(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << ">" << endl;
#endif
}


// comment callback
void xml_handler::cmnt(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << "<!--" << s << "-->" << endl;
#endif
}


}	/* namespace xqp */
