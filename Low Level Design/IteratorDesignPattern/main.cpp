#include "Library.hpp"
#include "BookIterator.hpp"
#include "Iterator.hpp"
#include "Book.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<Book*> books = {
        new Book(100,"Science"),
        new Book(200,"Maths"),
        new Book(300,"GK"),
        new Book(400,"Drawing")
    };

    Library* library = new Library(books);
    Iterator* iterator = library->createIterator();


    while(iterator->hasNext())
    {
        Book* book = (Book*) iterator->next();
        cout << book->getName() << " - ₹" << book->getPrice() << endl;
    }

    return 0;
}