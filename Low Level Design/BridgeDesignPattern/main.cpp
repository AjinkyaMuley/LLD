#include "Device.hpp"
#include "RemoteControl.hpp"
#include "TV.hpp"
#include "Radio.hpp"
#include "BasicRemoteControl.hpp"
#include "AdvancedRemoteControl.hpp"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    Device* tv = new TV();
    Device*  radio = new Radio();

    RemoteControl* tvRemote = new BasicRemoteControl(tv);
    RemoteControl* radioRemote = new AdvancedRemoteControl(radio);

    cout << "Using TV Remote: " << endl;
    tvRemote->turnOn();
    tvRemote->setVolume(20);
    tvRemote->turnOff();

    cout << endl << "Using Advanced Radio Remote" << endl;
    radioRemote->turnOn();
    radioRemote->setVolume(15);
    ((AdvancedRemoteControl*) radioRemote)->mute();
    radioRemote->turnOff();

    return 0;
}