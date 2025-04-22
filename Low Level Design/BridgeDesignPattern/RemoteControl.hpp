#ifndef REMOTECONTROL_HPP
#define REMOTECONTROL_HPP

#include "Device.hpp"
#include <bits/stdc++.h>
using namespace std;

class RemoteControl{

    protected:
        Device* device;

    public:

        RemoteControl(Device* device)
        {
            this->device = device;
        }

        void turnOn()
        {
            device->turnOn();
        }

        void turnOff()
        {
            device->turnOff();
        }

        void setVolume(int volume)
        {
            device->setVolume(volume);
        }
};


#endif