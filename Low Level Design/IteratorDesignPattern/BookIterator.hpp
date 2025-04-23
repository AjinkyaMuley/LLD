#ifndef BOOKITERATOR_HPP
#define BOOKITERATOR_HPP

#include "Iterator.hpp"
#include "Book.hpp"
#include <bits/stdc++.h>
using namespace std;

class BookIterator : public Iterator{
    vector<Book*> books;
    int index;

    public:
        BookIterator(vector<Book*> books)
        {
            this->books = books;
            this->index = 0;
        }

        bool hasNext() override
        {
            return index < books.size();
        }

        void* next() override
        {
            if(this->hasNext())
            {
                return books[index++];
            }
            return NULL;
        }
};


#endif