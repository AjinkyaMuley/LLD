#ifndef AGGREGATE_HPP
#define AGGREGATE_HPP

#include "Iterator.hpp"

class Aggregate{
    public:
        virtual Iterator* createIterator() = 0;
};


#endif