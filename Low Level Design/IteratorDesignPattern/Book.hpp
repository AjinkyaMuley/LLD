#ifndef BOOK_HPP
#define BOOK_HPP

#include <bits/stdc++.h>
using namespace std;

class Book{
    int price;
    string bookName;

    public:
        Book(int price,string bookName)
        {
            this->price = price;
            this->bookName = bookName;
        }    

        int getPrice()
        {
            return price;
        }

        string getName()
        {
            return bookName;
        }
};


#endif