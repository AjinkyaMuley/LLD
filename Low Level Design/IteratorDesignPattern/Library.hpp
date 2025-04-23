#ifndef LIBRARY_HPP
#define LIBRARY_HPP


#include "BookIterator.hpp"
#include "Book.hpp"
#include <bits/stdc++.h>
using namespace std;


class Library{
    vector<Book*> books;

    public:
        Library(vector<Book*>& books)
        {
            this->books = books;
        }

        Iterator* createIterator()
        {
            return new BookIterator(books);
        }
};


#endif