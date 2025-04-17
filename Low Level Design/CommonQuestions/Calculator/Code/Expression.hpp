#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "ArithmeticExpression.hpp"
#include "Operation.hpp"
#include <bits/stdc++.h>
using namespace std;

class ArithmeticExpression;
enum Operation;

class Expression : public ArithmeticExpression{
    public:
        ArithmeticExpression* left;
        ArithmeticExpression* right;
        Operation operation;

        Expression(ArithmeticExpression* left,ArithmeticExpression* right,Operation operation)
        {
            this->left = left;
            this->right = right;
            this->operation = operation;
        }

        int evaluate() override
        {
            int value = 0;
            switch(operation)
            {
                case Operation :: ADD:
                    value = left->evaluate() + right->evaluate();
                    break;
                case Operation ::SUBTRACT:
                    value = left->evaluate() - right->evaluate();
                    break;
                case Operation::MULTIPLY:
                    value = left->evaluate() * right->evaluate();
                    break;
                case Operation::DIVIDE:
                    value = left->evaluate() / right->evaluate();
                    break; 
            }
            cout << "Expression value is : " << value << endl;
            return value;
        }
};

#endif