#include<bits/stdc++.h>
using namespace std;

class DriveStrategy
{
    public:
        virtual void drive() = 0;
};

class NormalDriveStrategy : public DriveStrategy{
    public:
        void drive() override
        {
            cout<<"Normal Drive Capability" << endl;
        }
};

class SportsDriveStrategy : public DriveStrategy{
    public:
        void drive() override
        {
            cout<<"Sports Drive Capability" << endl;
        }
};


class Vehicle{
    public:
        DriveStrategy* driveObject;

        Vehicle(DriveStrategy* driveObj)
        {
            this->driveObject = driveObj;
        }
        void drive()
        {
            driveObject->drive();
        }
};

class OffRoadVehicle : public Vehicle{
    public:
        OffRoadVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class GoodsVehicle : public Vehicle{
    public:
        GoodsVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class SportsVehicle : public Vehicle{
    public:
        SportsVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class NormalVehicle : public Vehicle{
    public:
        NormalVehicle() : Vehicle(new NormalDriveStrategy()) {}                                   
};

int main()
{
    Vehicle* vehicle = new OffRoadVehicle();
    vehicle->drive();
    return 0;
}