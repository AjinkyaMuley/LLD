#ifndef PERCENTAGEEXPENSESPLIT_HPP
#define PERCENTAGEEXPENSESPLIT_HPP

#include "ExpenseSplit.hpp"
#include "Split.hpp"
#include <bits/stdc++.h>
using namespace std;

class Split;
class ExpenseSplit;

class PercentageExpenseSplit : public ExpenseSplit{
    public:
        void validateSplitRequest(vector<Split*> splitList,double totalAmount) override
        {
            
        }
};


#endif