#include <bits/stdc++.h>
using namespace std;

enum VehicleType
{
    CAR,
    SUV,
    SEDAN,
    HATCHBACK,
    TRUCK,
    VAN,
    MOTORCYCLE
};

enum Status
{
    ACTIVE,
    INACTIVE
};

class Vehicle
{
    int vehicleId;
    int vehicleNumber;
    VehicleType vehicleType;
    string companyName;
    string modelName;
    int kmDriven;
    string manufacturingDate;
    int average;
    int cc;
    int dailyRentalCost;
    int hourlyRentalCost;
    int noOfSeats;
    Status status;

public:
    int getVehicleId()
    {
        return vehicleId;
    }
    void setVehicleId(int vehicleId)
    {
        this->vehicleId = vehicleId;
    }
    int getVehicleNumber()
    {
        return vehicleNumber;
    }
    void setVehicleNumber(int vehicleNumber)
    {
        this->vehicleNumber = vehicleNumber;
    }
    VehicleType getVehicleType()
    {
        return vehicleType;
    }
    void setVehicleType(VehicleType vehicleType)
    {
        this->vehicleType = vehicleType;
    }
    string getCompanyName()
    {
        return companyName;
    }
    void setCompanyName(string companyName)
    {
        this->companyName = companyName;
    }
    string getModelName()
    {
        return modelName;
    }
    void setModelName(string modelName)
    {
        this->modelName = modelName;
    }
    int getKmDriven()
    {
        return kmDriven;
    }
    void setKmDriven(int kmDriven)
    {
        this->kmDriven = kmDriven;
    }
    string getManufacturingDate()
    {
        return manufacturingDate;
    }
    void setManufacturingDate(string manufacturingDate)
    {
        this->manufacturingDate = manufacturingDate;
    }
    int getAverage()
    {
        return average;
    }
    void setAverage(int average)
    {
        this->average = average;
    }
    int getCc()
    {
        return cc;
    }
    void setCc(int cc)
    {
        this->cc = cc;
    }
    int getDailyRentalCost()
    {
        return dailyRentalCost;
    }
    void setDailyRentalCost(int dailyRentalCost)
    {
        this->dailyRentalCost = dailyRentalCost;
    }
    int getHourlyRentalCost()
    {
        return hourlyRentalCost;
    }
    void setHourlyRentalCost(int hourlyRentalCost)
    {
        this->hourlyRentalCost = hourlyRentalCost;
    }
    int getNoOfSeats()
    {
        return noOfSeats;
    }
    void setNoOfSeats(int noOfSeats)
    {
        this->noOfSeats = noOfSeats;
    }
    Status getStatus()
    {
        return status;
    }
    void setStatus(Status status)
    {
        this->status = status;
    }
};

class Car : public Vehicle
{
};

class Bike : public Vehicle
{
};

enum ReservationStatus
{
    SCHEDULED,
    CANCELLED,
    IN_PROGRESS,
    COMPLETED,
};

enum ReservationType
{
    HOURLY,
    DAILY
};

class Location
{
public:
    string address;
    int pincode;
    string city;
    string state;
    string country;

    Location(int pincode, string city, string state, string country)
    {
        this->pincode = pincode;
        this->city = city;
        this->state = state;
        this->country = country;
    }
};

class User
{
public:
    int userId;
    string userName;
    int drivingLicense;

    int getUserId()
    {
        return userId;
    }
    void setUserId(int userId)
    {
        this->userId = userId;
    }
    string getUserName()
    {
        return userName;
    }
    void setUserName(string userName)
    {
        this->userName = userName;
    }
    int getDrivingLicense()
    {
        return drivingLicense;
    }
    void setDrivingLicense(int drivingLicense)
    {
        this->drivingLicense = drivingLicense;
    }
};

class Reservation
{
public:
    int reservationId;
    Vehicle *vehicle;
    User *user;
    string bookingDate;
    string dateBookedFrom;
    string dateBookedTo;
    long long fromTimeStamp;
    long long toTimeStamp;
    Location *pickUpLocation;
    Location *dropLocation;
    ReservationType reservationType;
    ReservationStatus reservationStatus;

    int createReserve(User *user, Vehicle *vehicle)
    {
        reservationId = 12332;
        this->user = user;
        this->vehicle = vehicle;
        reservationType = DAILY;
        reservationStatus = SCHEDULED;

        return reservationId;
    }
};

class VehicleInventoryManagement
{
public:
    list<Vehicle *> vehicles;

    VehicleInventoryManagement(list<Vehicle *> vehicles)
    {
        this->vehicles = vehicles;
    }

    list<Vehicle *> getVehicles()
    {
        return vehicles;
    }

    void setVehicles(list<Vehicle *> vehicles)
    {
        this->vehicles = vehicles;
    }
};

class Store
{
public:
    int storeId;
    VehicleInventoryManagement *inventoryManagement;
    Location *location;
    list<Reservation *> reservations;

    list<Vehicle *> getVehicles(VehicleType vehicleType)
    {
        return inventoryManagement->getVehicles();
    }

    void setVehicles(list<Vehicle *> vehicles)
    {
        inventoryManagement = new VehicleInventoryManagement(vehicles);
    }

    Reservation *createReservation(User *user, Vehicle *vehicle)
    {
        Reservation *reservation = new Reservation();
        reservation->createReserve(user, vehicle);
        reservations.push_back(reservation);
        return reservation;
    }

    bool completeReservation(int reservationId)
    {
        return true;
    }
};

class VehicleRentalSystem
{
public:
    list<Store *> storeList;
    list<User *> userList;

    VehicleRentalSystem(list<Store *> storeList, list<User *> userList)
    {
        this->storeList = storeList;
        this->userList = userList;
    }

    Store *getStore(Location *location)
    {
        return storeList.front();
    }
};

class Bill
{
public:
    Reservation *reservation;
    double totalBillAmount;
    bool isBillPaid;

    Bill(Reservation *reservation)
    {
        this->reservation = reservation;
        this->totalBillAmount = computeBillAmount();
        isBillPaid = false;
    }

private:
    double computeBillAmount()
    {
        return 100.0;
    }
};

class Payment
{

public:
    void payBill(Bill *bill)
    {
    }
};


// ... existing code ...
list<User*> addUsers() {
    list<User*> users;
    User* user = new User();
    user->setUserId(1);
    user->setUserName("John Doe");
    user->setDrivingLicense(12345);
    users.push_back(user);
    return users;
}

list<Vehicle*> addVehicles() {
    list<Vehicle*> vehicles;
    Car* car = new Car();
    car->setVehicleId(1);
    car->setVehicleNumber(1234);
    car->setVehicleType(CAR);
    car->setCompanyName("Toyota");
    car->setModelName("Camry");
    vehicles.push_back(car);
    return vehicles;
}

list<Store*> addStores(list<Vehicle*> vehicles) {
    list<Store*> stores;
    Store* store = new Store();
    store->storeId = 1;
    store->inventoryManagement = new VehicleInventoryManagement(vehicles);
    stores.push_back(store);
    return stores;
}


int main()
{
    list<User *> users = addUsers();
    list<Vehicle *> vehicles = addVehicles();
    list<Store *> stores = addStores(vehicles);
    VehicleRentalSystem *system = new VehicleRentalSystem(stores, users);

    // user comes
    User* user = users.front();

    Location* location = new Location(12345, "New York", "NY", "USA");
    Store* store = system->getStore(location);

    list<Vehicle*> storeVehicles = store->getVehicles(CAR);

    Reservation* reservation = store->createReservation(user, storeVehicles.front());

    Bill* bill = new Bill(reservation);
    Payment* payment = new Payment();
    payment->payBill(bill);

    store->completeReservation(reservation->reservationId);

    return 0;
}