#include <bits/stdc++.h>
using namespace std;


class BasePizza
{
public:
    virtual int cost() = 0;
};

class FarmHouse : public BasePizza{
    public:
        int cost() override
        {
            return 200;
        }
};

class VegDelight : public BasePizza{
    public:
        int cost() override
        {
            return 120;
        }
};

class Margherita : public BasePizza{
    public:
        int cost() override
        {
            return 100;
        }
};


class ToppingDecorator : public BasePizza{
};

class ExtraCheese : public ToppingDecorator{
    BasePizza* pizza;

    public:
        ExtraCheese(BasePizza* pizza)
        {
            this->pizza = pizza;
        }

        int cost() override
        {
            return this->pizza->cost() + 10;
        }
};

class Mushroom : public ToppingDecorator{
    BasePizza* pizza;

    public: 
        Mushroom(BasePizza* pizza)
        {
            this->pizza = pizza;
        }

        int cost() override
        {
            return this->pizza->cost() + 15;
        }
};

int main()
{
    BasePizza* pizza = new ExtraCheese(new Margherita());
    cout << pizza->cost() << endl;

    BasePizza* pizza2 = new Mushroom(new ExtraCheese(new ExtraCheese(new VegDelight())));
    cout << pizza2->cost() << endl;

    return 0;
}