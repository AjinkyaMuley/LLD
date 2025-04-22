#ifndef TV_HPP
#define TV_HPP


#include "Device.hpp"
#include <bits/stdc++.h>
using namespace std;

class TV : public Device{
    int volume = 10;

    public:
        void turnOn() override
        {
            cout << "TV is turned ON." << endl;
        }

        void turnOff() override
        {
            cout << "TV is turned OFF " << endl;
        }

        void setVolume(int volume) override
        {
            this->volume = volume;
            cout << "TV volume is set to " << this->volume << endl;
        }
};


#endif