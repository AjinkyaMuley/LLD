#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
        virtual void drive()
        {
            cout << "normal drive capability" << endl;
        }
};

class SportsVehicle : Vehicle{
    public:
    void drive()
    {
        cout << "sports drive capability" << endl;
    }
};

class PassengerVehicle : Vehicle{
    public:

};

class OffRoadVehicle : Vehicle{
    public:
        void drive() override{
            cout << "sports drive capability" << endl;
        }
};

class GoodsVehicle : Vehicle{
    public:

};

int main()
{
    
    return 0;
}