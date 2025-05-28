#ifndef INSTRUMENTSERVICEFACTORY_HPP
#define INSTRUMENTSERVICEFACTORY_HPP

#include "CardService.hpp"
#include "BankService.hpp"
#include "InstrumentService.hpp"
#include "InstrumentService.hpp"
#include<bits/stdc++.h>
using namespace std;

class InstrumentServiceFactory {
    public:
        InstrumentService* getInstrumentService(InstrumentType instrumentType)
        {
            if(instrumentType == InstrumentType::BANK)
            {
                return new BankService();
            }
            else if(instrumentType == InstrumentType::CARD)
            {
                return new CardService();
            }
            return NULL;
        }
};

#endif