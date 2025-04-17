#ifndef UNEQUALEXPENSESPLIT_HPP
#define UNEQUALEXPENSESPLIT_HPP

#include "ExpenseSplit.hpp"
#include "Split.hpp"
#include <bits/stdc++.h>
using namespace std;

class Split;
class ExpenseSplit;

class UnequalExpenseSplit : public ExpenseSplit{
    public:
        void validateSplitRequest(vector<Split*> splitList,double totalAmount) override
        {

        }
};


#endif