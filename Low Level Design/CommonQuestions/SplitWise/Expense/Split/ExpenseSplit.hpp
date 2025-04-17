#ifndef EXPENSESPLIT_HPP
#define EXPENSESPLIT_HPP

#include "Split.hpp"
#include <bits/stdc++.h>
using namespace std;

class Split;

class ExpenseSplit{
    public:
        virtual void validateSplitRequest(vector<Split*> splitList,double totalAmount) = 0;
};


#endif
