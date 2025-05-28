#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../Instrument/InstrumentDO.hpp"
#include "Transaction.hpp"
#include<bits/stdc++.h>
using namespace std;

class Processor{
    public:
        Transaction* transaction;

        void processPayment(InstrumentDO* senderInstrumentDO,InstrumentDO* recieverInstrumentDO)
        {
            
        }
};

#endif