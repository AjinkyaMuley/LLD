#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include "InstrumentType.hpp"
#include <bits/stdc++.h>
using namespace std;

class Instrument
{
public:
    int instrumentID;
    int userID;
    InstrumentType instrumentType;

    // Getters
    int getInstrumentID() const
    {
        return instrumentID;
    }
    int getUserID() const
    {
        return userID;
    }
    InstrumentType getInstrumentType() const
    {
        return instrumentType;
    }

    // Setters
    void setInstrumentID(int id)
    {
        instrumentID = id;
    }
    void setUserID(int uid)
    {
        userID = uid;
    }
    void setInstrumentType(InstrumentType type)
    {
        instrumentType = type;
    }
};

#endif