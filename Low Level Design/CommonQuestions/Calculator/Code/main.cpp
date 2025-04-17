#include "ArithmeticExpression.hpp"
#include "Number.hpp"
#include "Expression.hpp"
#include "Operation.hpp"
#include <bits/stdc++.h>
using namespace std;

class ArithmeticExpression;
class Number;
class Expression;
enum Operation;

int main()
{
    ArithmeticExpression* two = new Number(2);
    ArithmeticExpression* one = new Number(1);
    ArithmeticExpression* seven = new Number(7);

    ArithmeticExpression* add = new Expression(one,seven,Operation::ADD);
    ArithmeticExpression* multiply = new Expression(two,add,Operation::MULTIPLY);

    cout << multiply->evaluate() << endl;

    return 0;
}
