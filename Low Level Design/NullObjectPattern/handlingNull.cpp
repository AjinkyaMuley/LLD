#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    virtual int getTankCapacity() = 0;
    virtual int getSeatingCapacity() = 0;
};

class Car : public Vehicle{
    public:
        int getTankCapacity() override
        {
            return 40;
        }

        int getSeatingCapacity() override
        {
            return 5;
        }
};

class NullVehicle : public Vehicle{
    public:
        int getTankCapacity() override
        {
            return 0;
        }

        int getSeatingCapacity() override
        {
            return 0;
        }
};

class VehicleFactory{
    public:
        static Vehicle* getVehicleObject(string vehicleType)
        {
            if(vehicleType == "CAR")
            {
                return new Car();
            }

            return new NullVehicle();
        }
};

void printVehicleDetails(Vehicle* vehicle)
{
    cout << "Seating Capacity: " << vehicle->getSeatingCapacity() << endl << "Fuel Tank Capacity: " << vehicle->getTankCapacity() << endl;
}

int main()
{
    // Vehicle* vehicle = VehicleFactory :: getVehicleObject("BIKE");
    Vehicle* vehicle = VehicleFactory :: getVehicleObject("CAR");

    printVehicleDetails(vehicle);    
    return 0;
}