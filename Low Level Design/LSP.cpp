#include <iostream>

// Base class
class Vehicle {
public:
    virtual int getNumberOfWheels() const = 0; // Pure virtual function
    virtual bool hasEngine() const = 0; // Pure virtual function
    virtual ~Vehicle() {} // Virtual destructor
};

// Interface for vehicles with engines
class EngineVehicle : public Vehicle {
public:
    bool hasEngine() const override {
        return true;
    }
};

// Motorcycle class
class Motorcycle : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // Motorcycles have 2 wheels
    }
};

// Car class
class Car : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 4; // Cars have 4 wheels
    }
};

// Bicycle class (does not have an engine)
class Bicycle : public Vehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // Bicycles have 2 wheels
    }
    
    bool hasEngine() const override {
        return false; // Bicycles don't have engines
    }
};

// Function to test LSP compliance
void printVehicleDetails(const Vehicle& v) {
    std::cout << "Number of wheels: " << v.getNumberOfWheels() << "\n";
    std::cout << "Has engine: " << (v.hasEngine() ? "Yes" : "No") << "\n\n";
}

int main() {
    Motorcycle moto;
    Car car;
    Bicycle cycle;

    std::cout << "Motorcycle details:\n";
    printVehicleDetails(moto);

    std::cout << "Car details:\n";
    printVehicleDetails(car);

    std::cout << "Bicycle details:\n";
    printVehicleDetails(cycle);

    return 0;
}
