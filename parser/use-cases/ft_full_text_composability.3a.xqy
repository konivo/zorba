doc("http://bstore1.example.com/full-text.xml")
/books/book[count(.//content ftcontains (("millicent" 
&& "marigold" distance at most 3 words ordered)
&& "quote.{0-5}" with wildcards with thesaurus at 
"http://bstore1.example.com/UsabilityThesaurus.xml"
relationship "synonyms" distance at most 3 words) 
&& "usability testing" && "iterations" with stemming 
distance at most 50 words)>0]
