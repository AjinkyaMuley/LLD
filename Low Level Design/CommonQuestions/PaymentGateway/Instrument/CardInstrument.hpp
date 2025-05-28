#ifndef CARDINSTRUMENT_HPP
#define CARDINSTRUMENT_HPP

#include "Instrument.hpp"
#include<bits/stdc++.h>
using namespace std;

class CardInstrument : public Instrument{
    public:
        string cardNumber;
        string cvvNumber;
};

#endif