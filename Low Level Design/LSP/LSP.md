# Liskov Substitution Principle (LSP) in C++

## **Introduction**
The **Liskov Substitution Principle (LSP)** is one of the five SOLID principles of object-oriented programming. It ensures that **a derived class can replace its base class without altering the correctness of the program**.

### **Why is LSP Important?**
Consider a base class `Vehicle`, extended by `Car`, `Motorcycle`, and `Bicycle`. If the base class does not correctly define its behavior, replacing it with derived classes can cause unexpected errors or incorrect results.

LSP ensures that any subclass can be used in place of its parent class **without breaking the program**.

---

## **1. Breaking LSP: What’s Wrong in the Initial Approach?**
The initial approach violates LSP in the following ways:

1. **Incorrect Default Behavior:**
   - The base class `Vehicle` defines `getNumberOfWheels()` with a default value of `2`, assuming all vehicles have 2 wheels.  
   - This breaks expectations when a `Car` object (which has 4 wheels) replaces a `Vehicle`.

2. **Lack of a Proper Engine Definition:**
   - The `EngineVehicle` subclass introduces an `Engine` class, but `Vehicle` does not define a standard `hasEngine()` method.
   - This makes it unclear which vehicles have an engine, leading to unpredictable behavior.

### **Example of LSP Violation**
```cpp
Vehicle* v = new Car();
std::cout << v->getNumberOfWheels(); // This should return 4, but in the original approach, it returns 2!
```
This breaks the principle because `Car` **cannot fully substitute** `Vehicle` without altering expected behavior.

---

## **2. Fixing the Problem: LSP-Compliant Approach**
### **✅ Steps to Fix LSP**
1. **Define an abstract base class (`Vehicle`)**  
   - It should only declare methods every vehicle must implement (`getNumberOfWheels()` and `hasEngine()`).
   - This ensures **each vehicle explicitly defines its own number of wheels and engine presence**.

2. **Introduce an Interface for Engine Vehicles (`EngineVehicle`)**  
   - This ensures that only vehicles with an engine override `hasEngine()`, avoiding unnecessary methods in `Bicycle`.

3. **Correctly Implement Each Vehicle Class**  
   - `Car` and `Motorcycle` inherit from `EngineVehicle` and must define `getNumberOfWheels()`.
   - `Bicycle` inherits from `Vehicle` and must explicitly set `hasEngine()` to `false`.

---

### **✅ LSP-Compliant C++ Code**
```cpp
#include <iostream>

// Base class: Defines common vehicle behavior
class Vehicle {
public:
    virtual int getNumberOfWheels() const = 0; // Pure virtual function
    virtual bool hasEngine() const = 0; // Pure virtual function
    virtual ~Vehicle() {} // Virtual destructor for proper cleanup
};

// Derived class: Represents engine-based vehicles
class EngineVehicle : public Vehicle {
public:
    bool hasEngine() const override {
        return true; // All EngineVehicles have engines
    }
};

// Derived class: Motorcycle (inherits from EngineVehicle)
class Motorcycle : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // Motorcycles have 2 wheels
    }
};

// Derived class: Car (inherits from EngineVehicle)
class Car : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 4; // Cars have 4 wheels
    }
};

// Derived class: Bicycle (inherits from Vehicle but does NOT have an engine)
class Bicycle : public Vehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // Bicycles have 2 wheels
    }
    
    bool hasEngine() const override {
        return false; // Bicycles don't have engines
    }
};

// Function to demonstrate LSP compliance
void printVehicleDetails(const Vehicle& v) {
    std::cout << "Number of wheels: " << v.getNumberOfWheels() << "\n";
    std::cout << "Has engine: " << (v.hasEngine() ? "Yes" : "No") << "\n\n";
}

int main() {
    Motorcycle moto;
    Car car;
    Bicycle cycle;

    std::cout << "Motorcycle details:\n";
    printVehicleDetails(moto); // Should print 2 wheels and has engine

    std::cout << "Car details:\n";
    printVehicleDetails(car); // Should print 4 wheels and has engine

    std::cout << "Bicycle details:\n";
    printVehicleDetails(cycle); // Should print 2 wheels and NO engine

    return 0;
}
```

---

## **3. How This Code Follows LSP**
1. **No Incorrect Assumptions in the Base Class**
   - `Vehicle` no longer assumes **all vehicles have 2 wheels**.
   - `Vehicle` **does not assume every vehicle has an engine**, making it safe for bicycles.

2. **Derived Classes Can Fully Replace the Base Class**
   - The `printVehicleDetails` function **works for any `Vehicle` subclass** without modifying behavior.
   - You can **substitute `Car`, `Motorcycle`, or `Bicycle` for `Vehicle`**, and the output remains **logically correct**.

3. **Logical Separation of Engine and Non-Engine Vehicles**
   - Instead of putting `hasEngine()` in `Vehicle`, **we introduced `EngineVehicle`**, ensuring only appropriate classes define it.
   - This prevents **illogical cases like `Bicycle` having an engine function**.

---

## **4. Testing LSP Compliance**
### **✅ Expected Output**
```
Motorcycle details:
Number of wheels: 2
Has engine: Yes

Car details:
Number of wheels: 4
Has engine: Yes

Bicycle details:
Number of wheels: 2
Has engine: No
```
**🟢 Everything works as expected, meaning LSP is successfully implemented!**

---

## **5. Real-World Applications of LSP**
- **Game Development:**  
  - A `Player` class should be replaceable with `Mage`, `Warrior`, or `Archer` without breaking mechanics.
- **Banking Systems:**  
  - A `BankAccount` should support both `SavingsAccount` and `CurrentAccount` without inconsistencies.
- **Traffic Management:**  
  - A `TrafficSignal` should allow `PedestrianSignal` and `VehicleSignal` without breaking program logic.

---

## **6. Final Thoughts**
### **✅ Key Takeaways from LSP:**
1. **Base classes should only define behavior that makes sense for ALL derived classes.**  
2. **Derived classes must be able to fully substitute the base class without unexpected behavior.**  
3. **Avoid introducing methods in the base class that some derived classes cannot logically implement.**  

