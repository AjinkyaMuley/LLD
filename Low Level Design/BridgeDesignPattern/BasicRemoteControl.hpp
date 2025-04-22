#ifndef BASICREMOTECONTROL_HPP
#define BASICREMOTECONTROL_HPP


#include "RemoteControl.hpp"

class BasicRemoteControl : public RemoteControl{
    public:
        BasicRemoteControl(Device* device) : RemoteControl(device) {}
};

#endif