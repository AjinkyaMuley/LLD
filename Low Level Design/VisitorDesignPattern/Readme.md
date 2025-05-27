# Visitor Design Pattern - Hotel Room Management System

## Table of Contents
1. [Overview](#overview)
2. [What is the Visitor Design Pattern?](#what-is-the-visitor-design-pattern)
3. [Code Structure Analysis](#code-structure-analysis)
4. [Class Diagram](#class-diagram)
5. [Sequence Diagram](#sequence-diagram)
6. [Activity Diagram](#activity-diagram)
7. [Use Case Diagram](#use-case-diagram)
8. [Object Interaction Flow](#object-interaction-flow)
9. [Benefits and Trade-offs](#benefits-and-trade-offs)
10. [Implementation Details](#implementation-details)
11. [How to Run](#how-to-run)

## Overview

This project demonstrates the **Visitor Design Pattern** implementation using a Hotel Room Management System. The system handles different types of rooms (Single, Double, Deluxe) and performs various operations (Pricing, Maintenance) on them without modifying the room classes themselves.

## What is the Visitor Design Pattern?

The Visitor Design Pattern is a behavioral design pattern that allows you to define new operations on a set of objects without changing their classes. It separates algorithms from the objects on which they operate by moving the operational logic into separate visitor classes.

### Key Components:
- **Element Interface**: Defines the `accept()` method that takes a visitor
- **Concrete Elements**: Implement the element interface (Room types)
- **Visitor Interface**: Declares visit methods for each concrete element type
- **Concrete Visitors**: Implement specific operations (Pricing, Maintenance)

## Code Structure Analysis

```
VisitorDesignPattern/
├── RoomElement.hpp          # Abstract Element Interface
├── SingleRoom.hpp/.cpp      # Concrete Element
├── DoubleRoom.hpp/.cpp      # Concrete Element  
├── DeluxeRoom.hpp/.cpp      # Concrete Element
├── RoomVisitor.hpp          # Abstract Visitor Interface
├── RoomPricingVisitor.hpp   # Concrete Visitor
├── RoomMaintenanceVisitor.hpp # Concrete Visitor
└── main.cpp                 # Client Code
```

## Class Diagram

The class diagram shows the structure of the Visitor Design Pattern implementation. It illustrates the relationship between the abstract `RoomElement` and `RoomVisitor` classes, their concrete implementations, and how they interact with each other.

**Key relationships:**
- **Inheritance**: Concrete rooms inherit from `RoomElement`
- **Inheritance**: Concrete visitors inherit from `RoomVisitor` 
- **Dependency**: `RoomElement` uses `RoomVisitor` through the accept() method
- **Visits**: Each visitor can visit all room types

*Refer to the Class Diagram artifact above for the visual representation.*

## Sequence Diagram

The sequence diagram demonstrates the complete interaction flow between objects during the execution of the Visitor pattern. It shows how the double dispatch mechanism works through the combination of `accept()` and `visit()` methods.

**Key interactions:**
1. **Object Creation**: Client creates room and visitor objects
2. **Pricing Phase**: Each room accepts the pricing visitor, which sets appropriate prices
3. **Maintenance Phase**: Each room accepts the maintenance visitor for operations

**Double Dispatch Flow:**
- Client calls `room.accept(visitor)`
- Room calls `visitor.visit(this)` 
- Visitor executes the appropriate operation based on room type

*Refer to the Sequence Diagram artifact above for the detailed interaction flow.*

## Activity Diagram

The activity diagram shows the step-by-step process flow of the hotel management system using the Visitor pattern. It illustrates both the main execution flow and the internal visitor pattern mechanism.

**Main Flow:**
1. **Initialization**: Create room objects and visitors
2. **Pricing Phase**: Apply pricing logic to all rooms
3. **Maintenance Phase**: Perform maintenance on all rooms

**Visitor Pattern Flow:**
- `room.accept(visitor)` → `visitor.visit(room)` → Execute Operation → Return

*Refer to the Activity Diagram artifact above for the complete process flow visualization.*

## Use Case Diagram

The use case diagram illustrates the real-world usage scenarios of the hotel management system and shows how different actors interact with the system operations.

**Actors:**
- **Hotel Manager**: Responsible for calculating room pricing
- **Maintenance Staff**: Performs room maintenance operations  
- **Developer**: Adds new operations without modifying existing code

**Use Cases:**
- **Calculate Room Pricing**: Sets appropriate prices for different room types
- **Perform Room Maintenance**: Handles cleaning and repair operations
- **Add New Operations**: Extends functionality (future enhancement)

**Room Types**: All operations can be applied to Single, Double, and Deluxe rooms uniformly through the Visitor pattern.

*Refer to the Use Case Diagram artifact above for the visual representation with actors, use cases, and their relationships.*

## Object Interaction Flow

The object interaction flow diagram illustrates the three-layer architecture of the Visitor pattern implementation and shows how objects communicate with each other during execution.

**Three-Layer Architecture:**
1. **Client Layer**: Contains the main application logic (`main.cpp`)
2. **Element Layer**: Contains room objects and the `RoomElement` interface
3. **Visitor Layer**: Contains visitor objects and the `RoomVisitor` interface

**Interaction Steps:**
1. **Object Creation**: Client creates room and visitor instances
2. **Method Invocation**: Client calls `room.accept(visitor)`
3. **Double Dispatch**: Room calls `visitor.visit(this)`
4. **Operation Execution**: Visitor performs the specific operation
5. **Return Control**: Control flows back to the client

**Key Relationships:**
- **Implements**: Concrete classes implement their respective interfaces
- **Creates & Uses**: Client creates and manages all objects
- **Accept/Visit**: Rooms and visitors interact through double dispatch

*Refer to the Object Interaction Flow artifact above for the detailed architectural view and interaction patterns.*│  │ DeluxeRoom  │ │
        │  │             │  │             │  │             │ │
        │  │ +roomPrice  │  │ +roomPrice  │  │ +roomPrice  │ │
        │  │ +accept()   │  │ +accept()   │  │ +accept()   │ │
        │  └─────────────┘  └─────────────┘  └─────────────┘ │
        │         │               │               │           │
        │         └───────────────┼───────────────┘           │
        │                         │                           │
        │              implements │                           │
        │                         ▼                           │
        │               ┌─────────────────┐                   │
        │               │  RoomElement    │                   │
        │               │  (Interface)    │                   │
        │               │                 │                   │
        │               │ +accept()=0     │                   │
        │               └─────────────────┘                   │
        └─────────────────────┬───────────────────────────────┘
                              │
                              │ interacts with
                              ▼
        ┌─────────────────────────────────────────────────────┐
        │                 VISITOR LAYER                       │
        │                                                     │
        │ ┌──────────────────┐    ┌─────────────────────────┐ │
        │ │ PricingVisitor   │    │ MaintenanceVisitor      │ │
        │ │                  │    │                         │ │
        │ │ +visit(Single)   │    │ +visit(Single)          │ │
        │ │ +visit(Double)   │    │ +visit(Double)          │ │
        │ │ +visit(Deluxe)   │    │ +visit(Deluxe)          │ │
        │ └──────────────────┘    └─────────────────────────┘ │
        │          │                         │                │
        │          └─────────────┬───────────┘                │
        │                        │                            │
        │             implements │                            │
        │                        ▼                            │
        │               ┌─────────────────┐                   │
        │               │  RoomVisitor    │                   │
        │               │  (Interface)    │                   │
        │               │                 │                   │
        │               │ +visit()=0      │                   │
        │               └─────────────────┘                   │
        └─────────────────────────────────────────────────────┘

                    INTERACTION FLOW DIAGRAM:

    Step 1: Object Creation
    Client ──creates──> Room Objects
    Client ──creates──> Visitor Objects

    Step 2: Method Invocation  
    Client ──calls──> room.accept(visitor)

    Step 3: Double Dispatch
    Room   ──calls──> visitor.visit(this)

    Step 4: Operation Execution
    Visitor ──performs──> Specific Operation
    
    Step 5: Return Control
    Visitor ──returns──> to Room
    Room    ──returns──> to Client

                    DETAILED CALL FLOW:

    ┌─────────────┐    accept(pricingVisitor)    ┌─────────────┐
    │ Client      │ ──────────────────────────> │ SingleRoom  │
    │ main()      │                             │             │
    └─────────────┘                             └─────────────┘
                                                       │
                                                       │ visit(this)
                                                       ▼
                                               ┌─────────────────┐
                                               │ PricingVisitor  │
                                               │                 │
                                               │ Sets roomPrice  │
                                               │ = 1000          │
                                               └─────────────────┘

    The same pattern repeats for:
    - DoubleRoom (price = 2000)  
    - DeluxeRoom (price = 5000)
    - MaintenanceVisitor operations
```

## Benefits and Trade-offs

### ✅ Benefits
1. **Open/Closed Principle**: Easy to add new operations without modifying existing classes
2. **Single Responsibility**: Each visitor handles one specific operation
3. **Type Safety**: Compile-time method resolution through method overloading
4. **Centralized Logic**: Related operations are grouped in visitor classes

### ⚠️ Trade-offs
1. **Adding New Elements**: Requires updating all visitor interfaces
2. **Circular Dependencies**: Elements and visitors depend on each other
3. **Breaking Encapsulation**: Visitors may need access to element internals
4. **Complexity**: Can be overkill for simple operations

## Implementation Details

### Key Design Decisions

1. **Forward Declarations**: Used to break circular dependencies
   ```cpp
   class RoomVisitor; // Forward declaration in room headers
   ```

2. **Double Dispatch**: Achieved through accept() and visit() method combination
   ```cpp
   void SingleRoom::accept(RoomVisitor* visitor) {
       visitor->visit(this);  // Double dispatch
   }
   ```

3. **Smart Pointers**: Used in main.cpp for better memory management
   ```cpp
   std::unique_ptr<RoomElement> singleRoomObj = std::make_unique<SingleRoom>();
   ```

### Code Flow Explanation

1. **Object Creation**: Room objects and visitor objects are created
2. **Accept Call**: Client calls `room->accept(visitor)`
3. **Visit Dispatch**: Room calls `visitor->visit(this)` 
4. **Operation Execution**: Visitor executes the specific operation
5. **Return**: Control returns to client

### Polymorphism in Action

```cpp
// Polymorphic container
std::vector<std::unique_ptr<RoomElement>> rooms;
rooms.push_back(std::make_unique<SingleRoom>());
rooms.push_back(std::make_unique<DoubleRoom>());

// Polymorphic operation
for(auto& room : rooms) {
    room->accept(pricingVisitor.get());  // Correct visit() method called
}
```

## How to Run

### Prerequisites
- C++14 or later compiler (g++, clang++)
- Make (optional)

### Compilation
```bash
# Using g++
g++ -std=c++14 *.cpp -o hotel_system

# Or compile individually
g++ -std=c++14 -c SingleRoom.cpp
g++ -std=c++14 -c DoubleRoom.cpp  
g++ -std=c++14 -c DeluxeRoom.cpp
g++ -std=c++14 -c main.cpp
g++ *.o -o hotel_system
```

### Execution
```bash
./hotel_system
```

### Expected Output
```
Pricing computation logic for single room
Single Room Price: 1000
Pricing computation logic for double room  
Double Room Price: 2000
Pricing computation logic for deluxe room
Deluxe Room Price: 5000
Performing maintenance on Single Room
Performing maintenance on Double Room
Performing maintenance on Deluxe Room
```

## Extending the System

### Adding New Room Type
1. Create new room class inheriting from `RoomElement`
2. Update all visitor interfaces to include new `visit()` method
3. Implement the visit method in all concrete visitors

### Adding New Operation
1. Create new visitor class inheriting from `RoomVisitor`
2. Implement all required `visit()` methods
3. Use the new visitor with existing room objects

### Example: Adding Suite Room
```cpp
// SuiteRoom.hpp
class SuiteRoom : public RoomElement {
public:
    int roomPrice = 0;
    void accept(RoomVisitor* visitor) override;
};

// Update RoomVisitor.hpp
class RoomVisitor {
public:
    virtual void visit(SingleRoom* room) = 0;
    virtual void visit(DoubleRoom* room) = 0;
    virtual void visit(DeluxeRoom* room) = 0;
    virtual void visit(SuiteRoom* room) = 0;  // New method
};
```

This implementation showcases the power and flexibility of the Visitor Design Pattern in creating maintainable and extensible object-oriented systems.
