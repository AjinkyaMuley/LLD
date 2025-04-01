#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Rectangle" << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle" << endl;
    }
};

class ShapeFactory
{
public:
    Shape *getShape(char input)
    {
        switch (input)
        {
        case 'R':
            return new Rectangle();
            break;
        case 'C':
            return new Circle();
            break;
        default:
            return NULL;
        }
    }
};

int main()
{
    ShapeFactory* shapeFactoryObj = new ShapeFactory();
    Shape* shapeObj = shapeFactoryObj->getShape('C');
    shapeObj->draw();

    return 0;
}