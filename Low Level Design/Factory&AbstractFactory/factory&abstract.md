# Factory Method and Abstract Factory Method

## 1. Introduction
Design patterns are essential in software development to provide reusable solutions for common problems. Two widely used creational design patterns are the **Factory Method** and **Abstract Factory Method**. This document explains these patterns using the provided C++ code.

---

## 2. Factory Method Pattern

### **Definition**
The **Factory Method Pattern** is a design pattern that provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created.

### **Key Characteristics**
- Defines an interface for object creation.
- Allows subclasses to decide which class to instantiate.
- Promotes loose coupling by separating object creation from its usage.

### **Implementation in the Provided Code**

In the given code, the `ShapeFactory` class implements the **Factory Method Pattern** by encapsulating the logic of object creation.

#### **Classes Explanation**
1. **Abstract Base Class (`Shape`)**:
   ```cpp
   class Shape
   {
   public:
       virtual void draw() = 0;
   };
   ```
   - This is an **abstract class** with a pure virtual function `draw()`, making it a base class for all shapes.
   - It ensures that all derived classes implement the `draw()` function.

2. **Concrete Implementations (`Rectangle`, `Circle`)**:
   ```cpp
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
   ```
   - These are concrete implementations of `Shape`.
   - The `draw()` function is overridden to display the shape type.

3. **Factory Class (`ShapeFactory`)**:
   ```cpp
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
   ```
   - The `getShape()` method **encapsulates the object creation logic**, so the main function does not directly create objects of `Rectangle` or `Circle`.
   - Based on the user input (`'R'` or `'C'`), it returns the corresponding `Shape` object.

4. **Client Code (`main()` function)**:
   ```cpp
   int main()
   {
       ShapeFactory* shapeFactoryObj = new ShapeFactory();
       Shape* shapeObj = shapeFactoryObj->getShape('C');
       shapeObj->draw();
       return 0;
   }
   ```
   - The client code requests an object from `ShapeFactory` instead of instantiating `Rectangle` or `Circle` directly.
   - This **promotes loose coupling** and improves maintainability.

### **Advantages of Factory Method**
- **Encapsulation**: The client code does not need to know the exact class being instantiated.
- **Loose Coupling**: Changes in object creation do not affect the client code.
- **Scalability**: Easily extendable by adding new `Shape` subclasses without modifying existing code.

---

## 3. Abstract Factory Method

### **Definition**
The **Abstract Factory Pattern** is an extension of the Factory Method Pattern. It provides an interface for creating families of related objects without specifying their concrete classes.

### **Key Characteristics**
- Used to create **families of related objects**.
- Prevents tight coupling between client code and concrete classes.
- Provides a level of abstraction over multiple factory methods.

### **Implementation in the Provided Code (Modified)**
To implement the **Abstract Factory Pattern**, we need to introduce another layer of abstraction by creating a factory interface.

#### **Abstract Factory Interface (`ShapeFactory`)**
```cpp
class ShapeFactory
{
public:
    virtual Shape* createShape() = 0;
};
```
- Defines a **common interface** for shape creation.
- Concrete factories will implement this interface.

#### **Concrete Factories (`RectangleFactory`, `CircleFactory`)**
```cpp
class RectangleFactory : public ShapeFactory
{
public:
    Shape* createShape() override
    {
        return new Rectangle();
    }
};

class CircleFactory : public ShapeFactory
{
public:
    Shape* createShape() override
    {
        return new Circle();
    }
};
```
- `RectangleFactory` and `CircleFactory` **create specific types of shapes**.
- The client interacts only with `ShapeFactory`, not with individual shape classes.

#### **Client Code Using Abstract Factory**
```cpp
int main()
{
    ShapeFactory* factory;
    factory = new CircleFactory();
    Shape* shape = factory->createShape();
    shape->draw();
    return 0;
}
```
- The client uses the `ShapeFactory` interface, and the concrete factory (`CircleFactory` or `RectangleFactory`) is decided at runtime.
- The client code does not know about `Rectangle` or `Circle`—it just interacts with `ShapeFactory`.

### **Advantages of Abstract Factory Pattern**
- **Encapsulation**: Factory logic is hidden from the client.
- **Scalability**: New families of objects can be introduced easily.
- **Flexibility**: Switching between different product families is seamless.

---

## 4. Difference Between Factory Method and Abstract Factory
| Feature              | Factory Method | Abstract Factory |
|----------------------|---------------|------------------|
| Purpose | Provides a way to instantiate an object | Provides a way to instantiate **families** of objects |
| Object Creation | Single factory method | Multiple factory classes |
| Flexibility | Creates individual objects | Creates groups of related objects |
| Complexity | Less complex | More complex due to multiple factories |
| Example in Code | `ShapeFactory::getShape()` | `RectangleFactory` and `CircleFactory` |

---

## 5. Conclusion
- **Use Factory Method** when you need a single method to create objects and want to encapsulate object creation logic.
- **Use Abstract Factory** when you need to create families of related objects and ensure consistency across products.
- Both patterns **promote loose coupling** and **improve maintainability** by abstracting the object creation process.

By understanding these patterns, developers can create more flexible and scalable software architectures.

