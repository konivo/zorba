/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fstream>

#include "timer.h"

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

#include "diagnostics/errors.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/dataguide.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


using namespace zorba;

using namespace zorba::store;


void readXmlFile(const char* fileName, std::string& xmlString)
{
  std::ifstream xmlFile(fileName);
  if(!xmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  xmlString.clear();

  char delim = '\n';

  while (xmlFile)
  {
    std::string tmp;
    getline(xmlFile, tmp, delim);
    xmlString += tmp;
    xmlString += delim;
  }
  xmlFile.close();
}


int main(int argc, const char * argv[])
{
  if (argc < 2 || argc > 4)
  {
    std::cerr << "usage: test_store -n <times> <input file name>" << std::endl;
  }

	Timer timer;
  std::string fileName;
  ulong numLoads = 0;

  int arg = 1;
  while (arg < argc)
  {
    if (strcmp(argv[arg], "-n") == 0)
    {
      arg++;
      numLoads = atol(argv[arg]);
    }
    else
    {
      fileName = argv[arg];
    }

    arg++;
  }

  std::cout << "doc file = " << fileName << std::endl << "numLoads = "
            << numLoads << std::endl;

  //
  // Store initialization
  //
  simplestore::SimpleStore* lStore = StoreManager::getStore();

  //
  // Test boost::shared_ptr
  //
#if 0
  zorba::store::OrdPath* ordp = new zorba::store::OrdPath();

  boost::shared_ptr<zorba::store::OrdPath> p1(ordp);
  boost::shared_ptr<zorba::store::OrdPath> p2(ordp);

  std::cout << "p1 count = " << p1.use_count()
            << " p2 count = " << p2.use_count() << std::endl;

  p2 = p1;
#endif

  //
  // Re-acquirable latch
  //
  lStore->getGlobalLock().rlock();
  // lStore->getGlobalLock().wlock(); this will block
  lStore->getGlobalLock().rlock(); // this is ok.
  lStore->getGlobalLock().unlock();
  lStore->getGlobalLock().unlock();

  //
  // RC_TIMMING
  //
  //#define RC_TIMMING

#ifdef RC_TIMMING

  ulong loop = 1000000;
  const char* data = "aaaaaaa0000000";
  ulong datalen = strlen(data);

  for (ulong i = 0; i < loop; i++)
  {
    char* tmp = new char[datalen + 1];
    memcpy(tmp, data, datalen);
    delete [] tmp;
  }

  timer.end();
  std::cout << "char-pointer alloc time : " << timer.getTime() << std::endl;
  timer.start();

  for (ulong i = 0; i < loop; i++)
  {
    xqpStringStore* tmp = new xqpStringStore(data);
    delete tmp;
  }

  timer.end();
  std::cout << "String-pointer alloc time : " << timer.getTime() << std::endl;
  timer.start();

  for (ulong i = 0; i < loop; i++)
  {
    xqpStringStore_t tmp = new xqpStringStore(data);
  }

  timer.end();
  std::cout << "String-handle alloc time : " << timer.getTime() << std::endl;
  timer.start();

#endif // RC_TIMMING

  //
  // Create collections
  //
  store::Collection_t coll1;
  store::Collection_t coll2;

  try
  {
    xqpStringStore_t uri(new xqpStringStore("http://MyCollection1"));
    coll1 = lStore->createCollection(uri);

    std::cout << coll1->getUri()->show() << std::endl;

    coll2 = lStore->createCollection(uri);
  }
  catch (error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
  }

  //
  // Repeatedly load an xml doc from a file to the store
  //

  double totalTime = 0;

  for (ulong i = 0; i < numLoads; i++)
  {
    timer.start();

    std::ifstream ifs;
    ifs.open(fileName.c_str(), std::ios::in);
    if(!ifs.is_open())
    {
      std::cerr << "Error while opening: " << fileName << std::endl;
      abort();
    }

    store::Item_t doc;
    xqpStringStore_t docuri(new xqpStringStore(fileName));

    try
    {
      doc = lStore->loadDocument(docuri, ifs);
    }
    catch (zorba::error::ZorbaError& e)
    {
      std::cout << e.theDescription << std::endl;
      return 1;
    }

    timer.end();
    if (i == 0)
      std::cout << "First loading time : " << timer.getTime() << std::endl;
    else
      totalTime += timer.getTime();

    lStore->deleteDocument(docuri);
    doc = 0;

    ifs.close();
  }

  if (numLoads > 1)
  {
    std::cout << "Average loading time : " << totalTime / (numLoads - 1) << std::endl;
  }

  //
  // Load the doc to the collection, and keep a ref to it.
  //
  std::ifstream xmlFile(fileName.c_str());
  if(!xmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  std::iostream xmlStream(xmlFile.rdbuf());
  store::Item_t doc;

  try
  {
    doc = coll1->loadDocument(xmlStream);
  }
  catch (zorba::error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
    return 1;
  }

  xmlFile.close();

  //
  // Destroy collection
  //
  lStore->deleteCollection(coll1->getUri()->getStringValue());
  coll1 = 0;

  //
  // Print out loaded document
  //
#if 0
  fileName += ".res";
  std::ofstream outXmlFile(fileName.c_str());
  if(!outXmlFile)
  {
    std::cerr << "Error while opening: " << fileName << std::endl;
    abort();
  }

  if (doc != NULL)
    outXmlFile << doc->show() << std::endl;
  else
    return 1;
#endif

  //
  // Test node references
  //
  store::Item_t uri;
  lStore->getReference(uri, doc);
  std::cout << "Reference URI for node: " << doc.getp() << " is: "
            << uri->getStringValue()->c_str() << std::endl;

  try
  {
    xqpStringStore_t uri(new xqpStringStore("http://MyCollection1"));
    coll1 = lStore->createCollection(uri);

    std::cout << coll1->getUri()->show() << std::endl;

    coll1->addNode(doc);
  }
  catch (error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
  }

  store::Item_t doc2;
  if (!lStore->getNodeByReference(doc2, uri)) {
    doc2 = NULL;
  }

  if (doc != doc2)
    std::cout << "ERROR" << std::endl;

  zorba::simplestore::XmlNode* rootNode =
      reinterpret_cast<zorba::simplestore::XmlNode*>(doc.getp());

  for (ulong i = 0; i < 3; i++)
  {
    zorba::simplestore::XmlNode* parent = rootNode;

    double factor = 0.0;
    if (i == 0) factor = 0.5;
    else if (i == 1) factor = 0.66;
    else if (i == 2) factor = 0.90;

    std::vector<const zorba::store::Item*> ctxPath;
    std::vector<const zorba::store::Item*> relPath;
    
    while (1)
    {
      ulong numChildren = parent->numChildren();
      if (numChildren == 0)
        break;

      ulong childPos = (ulong)(numChildren * factor);
      zorba::simplestore::XmlNode* child = parent->getChild(childPos);

      while (child->getNodeKind() != StoreConsts::elementNode)
      {
        childPos++;
        if (childPos == numChildren)
          break;

        child = parent->getChild(childPos);
      }

      if (childPos == numChildren)
        break;

      ctxPath.push_back(child->getNodeName());

      lStore->getReference(uri, child);
      std::cout << "Reference URI for node " << child << ":" 
                << child->getNodeName()->getStringValue()->c_str()
                << " at position " << childPos 
                << " is: " << uri->getStringValue()->c_str() << std::endl;

      Item_t child2;
      if (!lStore->getNodeByReference(child2, uri)) {
        child2 = NULL;
      }

      if (child != child2.getp())
        std::cout << "ERROR" << std::endl;

      parent = child;
    }

#ifdef DATAGUIDE
    if (rootNode->getDataGuide() != NULL)
    {
      bool found, unique;
      rootNode->getDataGuide()->getPathInfo(ctxPath, relPath, false, found, unique);
      std::cout << "Info for path : ";

      for (ulong i = 0; i < ctxPath.size(); i++)
        std::cout << "/" << *ctxPath[i]->getStringValue();

      std::cout << std::endl << "found = " << found << " unique = "
                << unique << std::endl;

      relPath.resize(1);
      relPath[0] = ctxPath[ctxPath.size()-1];
      ctxPath.resize(ctxPath.size()-1);

      rootNode->getDataGuide()->getPathInfo(ctxPath, relPath, false, found, unique);

      std::cout << "found = " << found << " unique = " << unique
                << std::endl << std::endl;
    }
#endif
  }

  //
  // Shutdown
  //
  lStore->deleteCollection(coll1->getUri()->getStringValue());
  coll1 = 0;
  doc = 0;
  doc2 = 0;

  lStore->shutdown();
  return 0;
}
