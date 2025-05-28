#ifndef InstrumentService_hpp
#define InstrumentService_hpp

#include "InstrumentDO.hpp"
#include "Instrument.hpp"
#include<bits/stdc++.h>
using namespace std;

class InstrumentService{
    public:
        static unordered_map<int,vector<Instrument*>> userVsInstruments;

        virtual InstrumentDO* addInstrument(InstrumentDO* instrumentDO) = 0;

        virtual vector<InstrumentDO*> getInstrumentsByUserID(int userID) = 0;
};

#endif