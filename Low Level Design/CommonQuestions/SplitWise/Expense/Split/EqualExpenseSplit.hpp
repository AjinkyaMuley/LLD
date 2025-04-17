#ifndef EQUALEXPENSESPLIT_HPP
#define EQUALEXPENSESPLIT_HPP

#include "Split.hpp"
#include "ExpenseSplit.hpp"
#include <bits/stdc++.h>
using namespace std;

class ExpenseSplit;
class Split;

class EqualExpenseSplit : public ExpenseSplit
{
public:
    void validateSplitRequest(vector<Split *> splitList, double totalAmount) override
    {
        double amountShouldBePresent = totalAmount / splitList.size();

        for (auto split : splitList)
        {
            if (split->getAmountOwe() != amountShouldBePresent)
            {
                throw runtime_error("Split amounts do not match the equal split requirement.");
            }
        }
    }
};
#endif