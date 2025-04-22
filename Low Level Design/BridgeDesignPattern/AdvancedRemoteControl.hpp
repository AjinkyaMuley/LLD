#ifndef ADVANCEDREMOTECONTROL_HPP
#define ADVANCEDREMOTECONTROL_HPP

#include "RemoteControl.hpp"


class AdvancedRemoteControl : public RemoteControl{
    public:
        AdvancedRemoteControl(Device* device) : RemoteControl(device) {}

        void mute()
        {
            cout << "Muting the device... " << endl;
            device->setVolume(0);
        }
};


#endif