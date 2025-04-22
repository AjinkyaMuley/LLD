#ifndef DEVICE_HPP
#define DEVICE_HPP


class Device{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual void setVolume(int volume) = 0;

};


#endif