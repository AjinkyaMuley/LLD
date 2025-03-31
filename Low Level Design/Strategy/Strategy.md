# Strategy Behavioral Design Pattern in C++

## Introduction
The **Strategy Pattern** is a behavioral design pattern that allows selecting an algorithm's behavior at runtime. Instead of implementing a specific behavior directly, a class delegates the behavior to a separate strategy class. This promotes flexibility, reusability, and maintainability of code.

## Key Principles
1. **Encapsulation of Behaviors:** Define a family of algorithms, encapsulate each one, and make them interchangeable.
2. **Delegation:** The context class delegates behavior implementation to a strategy object.
3. **Runtime Flexibility:** The client can dynamically change the behavior without modifying the context class.
4. **Open/Closed Principle:** New behaviors can be added without modifying existing code.

## Use Cases
- Different driving behaviors in a vehicle simulation.
- Payment methods selection (Credit Card, PayPal, etc.).
- Sorting algorithms that can be changed at runtime.
- Compression algorithms selection (ZIP, RAR, etc.).

## Implementation in C++

### Step 1: Define the Strategy Interface
```cpp
class DriveStrategy {
public:
    virtual void drive() = 0; // Pure virtual function (interface)
    virtual ~DriveStrategy() {} // Virtual destructor for cleanup
};
```

### Step 2: Implement Concrete Strategies
```cpp
class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Normal Drive Capability" << endl;
    }
};

class SportsDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Sports Drive Capability" << endl;
    }
};
```

### Step 3: Create a Context Class (`Vehicle`)
```cpp
class Vehicle {
protected:
    DriveStrategy* driveObject; // Pointer to strategy object

public:
    Vehicle(DriveStrategy* driveObj) : driveObject(driveObj) {} // Store strategy object

    void drive() {
        driveObject->drive(); // Delegate the behavior to the strategy
    }

    virtual ~Vehicle() { delete driveObject; } // Prevent memory leaks
};
```

### Step 4: Implement Different Vehicle Types
```cpp
class OffRoadVehicle : public Vehicle {
public:
    OffRoadVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class GoodsVehicle : public Vehicle {
public:
    GoodsVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class SportsVehicle : public Vehicle {
public:
    SportsVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class NormalVehicle : public Vehicle {
public:
    NormalVehicle() : Vehicle(new NormalDriveStrategy()) {}
};
```

### Step 5: Implement the Main Function
```cpp
int main() {
    Vehicle* vehicle = new GoodsVehicle(); // Use a pointer
    vehicle->drive();  // Output: "Normal Drive Capability"

    delete vehicle; // Free allocated memory
    return 0;
}
```

## How the Strategy Pattern Works
1. **Encapsulation of Behavior:** The `DriveStrategy` interface encapsulates different driving behaviors.
2. **Behavior Selection at Runtime:** The `Vehicle` is assigned a strategy dynamically (`new SportsDriveStrategy()` or `new NormalDriveStrategy()`).
3. **Code Reusability and Flexibility:** New driving behaviors can be added without modifying existing code.
4. **Prevention of Code Duplication:** The `Vehicle` class does not need multiple `if-else` conditions to handle different driving behaviors.

## Advantages of Using the Strategy Pattern
✅ **Extensibility:** Easily add new driving strategies without modifying existing code.
✅ **Flexibility:** The behavior can change dynamically at runtime.
✅ **Improved Code Maintenance:** Avoids complex conditional statements inside the `Vehicle` class.
✅ **Promotes SOLID Principles:** Encourages the Open/Closed Principle and Single Responsibility Principle.

## Conclusion
The **Strategy Pattern** is a powerful technique in **object-oriented design** that enhances flexibility and maintainability. In this example, different vehicles can have different driving behaviors, which can be changed dynamically without modifying the `Vehicle` class.

This pattern is widely used in software engineering for designing flexible and scalable systems.

---

### 🚀 **Happy Coding!** 🚀

