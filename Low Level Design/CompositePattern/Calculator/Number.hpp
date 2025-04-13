#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "ArithmeticExpression.hpp"
#include <bits/stdc++.h>
using namespace std;

class ArithmeticExpression;

class Number : public ArithmeticExpression{
    public: 
        int value;

        Number(int value)
        {
            this->value = value;
        }

        int evaluate() override
        {
            cout << "Number value is : " << this->value << endl;
            return value;
        }
};

#endif