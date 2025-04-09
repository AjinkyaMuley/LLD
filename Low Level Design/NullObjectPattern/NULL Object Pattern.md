🛠️ Null Object Design Pattern - C++ Implementation
This project demonstrates the Null Object Design Pattern using a simple Vehicle example.

🧠 What is the Null Object Pattern?
The Null Object Pattern is a behavioral design pattern that provides a default object (a "null" object) instead of nullptr or null when an object is expected but not available. This avoids the need to constantly check for null and helps simplify code logic.

💡 Why Use It?
Avoids nullptr checks throughout your code

Encapsulates default behavior for missing objects

Promotes code cleanliness and maintainability

🔧 Class Breakdown
1. Vehicle (Abstract Class)
Declares two pure virtual functions:

getTankCapacity()

getSeatingCapacity()

2. Car (Concrete Class)
Implements Vehicle

Returns:

Tank Capacity: 40

Seating Capacity: 5

3. NullVehicle (Concrete Class)
Also implements Vehicle

Returns:

Tank Capacity: 0

Seating Capacity: 0

Used when no valid vehicle type is found

4. VehicleFactory
Responsible for object creation

Returns Car if "CAR" is passed

Returns NullVehicle for unknown types

🧭 UML Class Diagram
plaintext
Copy
Edit
             +-----------------+
             |    Vehicle      |<---------------------------+
             +-----------------+                            |
             | +getTankCapacity()=0                         |
             | +getSeatingCapacity()=0                      |
             +-----------------+                            |
                     ^                                      |
         +-----------+------------+                         |
         |                        |                         |
+----------------+      +------------------+     +-----------------------+
|      Car       |      |   NullVehicle    |     |   VehicleFactory      |
+----------------+      +------------------+     +-----------------------+
| +getTankCapacity()    | +getTankCapacity()     | +getVehicleObject()   |
| +getSeatingCapacity() | +getSeatingCapacity()  +-----------------------+
+----------------+      +------------------+                            
🔄 Flowchart: Object Creation and Usage
plaintext
Copy
Edit
          +------------------------+
          |  main()                |
          +------------------------+
                    |
                    v
          +------------------------+
          | VehicleFactory::       |
          | getVehicleObject()     |
          +------------------------+
                    |
         +----------+------------+
         |                       |
         v                       v
  +--------------+       +----------------+
  |   Car()      |       |  NullVehicle() |
  +--------------+       +----------------+
         |                       |
         +-----------+-----------+
                     |
                     v
          +------------------------+
          | printVehicleDetails()  |
          +------------------------+
✅ Example Execution
cpp
Copy
Edit
Vehicle* vehicle = VehicleFactory::getVehicleObject("CAR");
printVehicleDetails(vehicle);
Output:

yaml
Copy
Edit
Seating Capacity: 5
Fuel Tank Capacity: 40
If an invalid type is passed:

cpp
Copy
Edit
Vehicle* vehicle = VehicleFactory::getVehicleObject("BIKE");
printVehicleDetails(vehicle);
Output:

yaml
Copy
Edit
Seating Capacity: 0
Fuel Tank Capacity: 0
📦 Benefits of Null Object Pattern in this Example
No need for:

cpp
Copy
Edit
if (vehicle != nullptr)
    vehicle->getTankCapacity();
Encapsulation of default behavior inside NullVehicle

Promotes Open/Closed Principle: New vehicles can be added without changing existing logic

📌 Conclusion
The Null Object Design Pattern helps handle the absence of a concrete class by providing a default object. This keeps your code clean, null-safe, and easier to manage. This project demonstrates the use of this pattern in a real-world scenario involving a VehicleFactory
