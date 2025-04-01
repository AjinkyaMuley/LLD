# Decorator Design Pattern in C++

## Introduction
The **Decorator Pattern** is a **structural** design pattern that allows behavior to be added to individual objects, either statically or dynamically, without modifying their class definition. It is particularly useful when we need to extend the functionality of objects in a flexible and reusable way.

In this document, we will explore the **Decorator Pattern** using a pizza ordering system as an example, demonstrating how we can dynamically add toppings to a base pizza.

---

## Understanding the Decorator Pattern
### Key Characteristics:
- **Encapsulation of Behavior**: Additional responsibilities can be added to an object without modifying its existing structure.
- **Composition Over Inheritance**: Instead of extending functionality through subclassing, we achieve it by composing objects.
- **Flexible and Scalable**: Multiple decorators can be combined in different ways to modify behavior.

### Structure of the Pattern
The **Decorator Pattern** consists of:
1. **Component (BasePizza)**: Defines the common interface for both concrete and decorated objects.
2. **Concrete Component (FarmHouse, VegDelight, Margherita)**: Implements the base functionality.
3. **Decorator (ToppingDecorator)**: Extends the base component by wrapping it.
4. **Concrete Decorators (ExtraCheese, Mushroom)**: Modify the behavior dynamically by adding new functionality.

---

## Implementation in C++

```cpp
#include <bits/stdc++.h>
using namespace std;

// Base Component
class BasePizza {
public:
    virtual int cost() = 0;  // Pure virtual function
};

// Concrete Components (Base Pizza Types)
class FarmHouse : public BasePizza {
public:
    int cost() override { return 200; }
};

class VegDelight : public BasePizza {
public:
    int cost() override { return 120; }
};

class Margherita : public BasePizza {
public:
    int cost() override { return 100; }
};

// Decorator
class ToppingDecorator : public BasePizza {
};

// Concrete Decorators
class ExtraCheese : public ToppingDecorator {
    BasePizza* pizza;
public:
    ExtraCheese(BasePizza* pizza) { this->pizza = pizza; }
    int cost() override { return this->pizza->cost() + 10; }
};

class Mushroom : public ToppingDecorator {
    BasePizza* pizza;
public:
    Mushroom(BasePizza* pizza) { this->pizza = pizza; }
    int cost() override { return this->pizza->cost() + 15; }
};

int main() {
    // Creating a Margherita pizza with Extra Cheese
    BasePizza* pizza = new ExtraCheese(new Margherita());
    cout << "Cost of Margherita with Extra Cheese: " << pizza->cost() << endl;

    // Creating a VegDelight pizza with double Extra Cheese and Mushroom
    BasePizza* pizza2 = new Mushroom(new ExtraCheese(new ExtraCheese(new VegDelight())));
    cout << "Cost of VegDelight with double Extra Cheese and Mushroom: " << pizza2->cost() << endl;

    return 0;
}
```

---

## Explanation
### 1. **Base Component (BasePizza)**
```cpp
class BasePizza {
public:
    virtual int cost() = 0;
};
```
This is the **Component** in the Decorator Pattern, defining a common interface for all pizzas.

### 2. **Concrete Components (FarmHouse, VegDelight, Margherita)**
```cpp
class Margherita : public BasePizza {
public:
    int cost() override { return 100; }
};
```
Each subclass represents a specific type of pizza with a fixed base price.

### 3. **Decorator (ToppingDecorator)**
```cpp
class ToppingDecorator : public BasePizza {
};
```
This is an abstract class that extends `BasePizza`. All toppings will be subclasses of this decorator.

### 4. **Concrete Decorators (ExtraCheese, Mushroom)**
```cpp
class ExtraCheese : public ToppingDecorator {
    BasePizza* pizza;
public:
    ExtraCheese(BasePizza* pizza) { this->pizza = pizza; }
    int cost() override { return this->pizza->cost() + 10; }
};
```
These decorators dynamically add toppings to a pizza while maintaining the existing functionality.

### 5. **Usage in `main()`**
```cpp
BasePizza* pizza = new ExtraCheese(new Margherita());
cout << "Cost of Margherita with Extra Cheese: " << pizza->cost() << endl;
```
Here, `ExtraCheese` wraps a `Margherita` pizza, adding 10 to its base cost of 100.

```cpp
BasePizza* pizza2 = new Mushroom(new ExtraCheese(new ExtraCheese(new VegDelight())));
```
This creates a `VegDelight` pizza and decorates it with:
1. Extra Cheese (+10)
2. Another Extra Cheese (+10)
3. Mushroom (+15)

Final cost = 120 + 10 + 10 + 15 = **155**.

---

## Advantages of Decorator Pattern
1. **Open/Closed Principle**: New functionality can be added without modifying existing classes.
2. **Flexible Composition**: Objects can be wrapped in multiple decorators to achieve different behaviors.
3. **Avoids Subclass Explosion**: Instead of creating multiple subclasses for different combinations, we use decorators.

## Disadvantages of Decorator Pattern
1. **Complexity**: The pattern increases the number of objects, making debugging harder.
2. **Difficult Object Identity Management**: Since decorators wrap objects, checking for a specific type requires careful handling.

---

## When to Use the Decorator Pattern
- When you want to **add responsibilities to objects dynamically** without affecting others.
- When subclassing would lead to an explosion of classes for different variations.
- When you need **flexible** and **reusable** object composition.

---

## Conclusion
The **Decorator Pattern** is a powerful tool for extending functionality dynamically. In our pizza example, it allows adding toppings at runtime without modifying the core pizza classes. This keeps the system flexible and modular, demonstrating **composition over inheritance** in real-world applications.
