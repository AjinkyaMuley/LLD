# Vehicle Rental System - Low-Level Design

## Overview
The Vehicle Rental System is a software model designed using various Object-Oriented Programming (OOP) principles and design patterns. It provides functionality for users to rent vehicles from stores based on availability, manage reservations, generate bills, and process payments.

---

## Design Patterns Used

### 1. **Factory Pattern**
   - Used in `addUsers()`, `addVehicles()`, and `addStores()` methods to create lists of users, vehicles, and stores dynamically.
   - This abstracts the creation logic from the main program.

### 2. **Singleton Pattern**
   - Although not explicitly implemented, `VehicleRentalSystem` could be a good candidate for a singleton, ensuring only one instance manages all stores and users.

### 3. **Builder Pattern**
   - The `Vehicle` class follows a builder-like pattern with multiple setter methods (`setVehicleId()`, `setCompanyName()`, etc.), allowing step-by-step object construction.

### 4. **Prototype Pattern**
   - The system could be extended to support deep copying of vehicles or reservations when multiple users rent the same vehicle over different periods.

### 5. **Observer Pattern** (Potential Enhancement)
   - Could be implemented to notify users when a vehicle becomes available.

### 6. **Strategy Pattern**
   - Used in `Bill` class, where the `computeBillAmount()` method could be extended to handle different pricing strategies based on vehicle type and reservation duration.

### 7. **Decorator Pattern**
   - Can be extended in `Payment` to support multiple payment methods like Credit Card, UPI, or Wallets.

---

## UML-Class Diagram Representation

Below is a textual representation of the UML diagram:

```
+--------------------+
|   VehicleRentalSystem  |
|--------------------|
| - storeList        |
| - userList         |
|--------------------|
| + getStore()       |
+--------------------+
           |
           | has
           v
+--------------------+
|        Store      |
|--------------------|
| - storeId         |
| - inventoryMgmt   |
| - location        |
| - reservations    |
|--------------------|
| + getVehicles()   |
| + createReservation() |
| + completeReservation() |
+--------------------+
           |
           | owns
           v
+--------------------+
|  VehicleInventoryMgmt |
|--------------------|
| - vehicles        |
|--------------------|
| + getVehicles()   |
+--------------------+
           |
           | contains
           v
+--------------------+
|     Vehicle       |
|--------------------|
| - vehicleId       |
| - vehicleNumber   |
| - companyName     |
| - modelName       |
|--------------------|
| + get/set methods |
+--------------------+
     /  \
    /    \ has
+--------+  +--------+
|  Car   |  |  Bike  |
+--------+  +--------+

+--------------------+
|      User         |
|--------------------|
| - userId          |
| - userName        |
| - drivingLicense  |
|--------------------|
| + get/set methods |
+--------------------+
           |
           | books
           v
+--------------------+
|   Reservation     |
|--------------------|
| - reservationId   |
| - vehicle         |
| - user            |
| - status         |
|--------------------|
| + createReserve() |
+--------------------+
           |
           | generates
           v
+--------------------+
|      Bill        |
|--------------------|
| - totalAmount    |
| - isBillPaid     |
|--------------------|
| + computeBill()  |
+--------------------+
           |
           | processed by
           v
+--------------------+
|     Payment      |
|--------------------|
| + payBill()      |
+--------------------+
```

This UML structure shows the relationships between classes, indicating how the system components interact.

---

## Conclusion
This system follows a modular OOP design incorporating multiple design patterns, making it extensible and maintainable. Future enhancements can include implementing the Observer pattern for availability notifications and Strategy pattern for dynamic pricing models.
