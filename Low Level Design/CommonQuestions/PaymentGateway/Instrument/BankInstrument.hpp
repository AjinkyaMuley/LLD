#ifndef BANKINSTRUMENT_HPP
#define BANKINSTRUMENT_HPP

#include "Instrument.hpp"
#include<bits/stdc++.h>
using namespace std;

class BankInstrument : public Instrument{
    public:
        string bankAccountNumber;
        string ifscCOde;
};

#endif