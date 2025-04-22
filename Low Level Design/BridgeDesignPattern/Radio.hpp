#ifndef RADIO_HPP
#define RADIO_HPP


#include "Device.hpp"
#include <bits/stdc++.h>
using namespace std;

class Radio : public Device{
    int volume = 5;

    public:
        void turnOn() override
        {
            cout << "Radio is turned ON" << endl;
        }

        void turnOff() override
        {
            cout << "Radio is turned OFF" << endl;
        }

        void setVolume(int volume) override
        {
            this->volume = volume;
            cout << "Radio volume is set to " << this->volume << endl;
        }
};


#endif