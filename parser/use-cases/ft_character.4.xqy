for $book in doc("http://bstore1.example.com/full-text.xml")
   /books/book[. ftcontains "AIDS" case insensitive]   
where count($book) > 0  
return $book
