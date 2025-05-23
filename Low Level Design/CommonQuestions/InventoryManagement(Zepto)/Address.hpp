#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <bits/stdc++.h>
using namespace std;

class Address {
    public:
        int pinCode;
        string city;
        string state;

        Address(int pinCode, string city, string state)
        {
            this->pinCode = pinCode;
            this->city = city;
            this->state = state;
        }

        // Getter and Setter for pinCode
        int getPinCode() {
            return pinCode;
        }

        void setPinCode(int pinCode) {
            this->pinCode = pinCode;
        }

        // Getter and Setter for city
        string getCity() {
            return city;
        }

        void setCity(string city) {
            this->city = city;
        }

        // Getter and Setter for state
        string getState() {
            return state;
        }

        void setState(string state) {
            this->state = state;
        }
};

#endif