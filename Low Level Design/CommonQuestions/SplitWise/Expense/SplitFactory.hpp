#ifndef SPLITFACTORYHPP
#define SPLITFACTORYHPP

#include "ExpenseSplitType.hpp"
#include "./Split/EqualExpenseSplit.hpp"
#include "./Split/PercentageExpenseSplit.hpp"
#include "./Split/UnequalExpenseSplit.hpp"
#include "./Split/ExpenseSplit.hpp"
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class ExpenseSplit;
enum ExpenseSplitType;
class EequalExpenseSplit;
class PercentageExpenseSplit;
class UnequalExpenseSplit;

class SplitFactory
{
public:
    static ExpenseSplit *getSplitObject(ExpenseSplitType splitType)
    {
        switch (splitType)
        {
        case EQUAL:
            return new EqualExpenseSplit();
        case UNEQUAL:
            return new UnequalExpenseSplit();
        case PERCENTAGE:
            return new PercentageExpenseSplit();
        default:
            return nullptr;
        }
    }
};

#endif