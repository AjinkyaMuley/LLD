#ifndef BAKSERVICE_HPP
#define BAKSERVICE_HPP

#include "InstrumentService.hpp"
#include "BankInstrument.hpp"
#include "Instrument.hpp"
#include "InstrumentDO.hpp"
#include<bits/stdc++.h>
using namespace std;

class BankService : public InstrumentService{
    public:
        InstrumentDO* addInstrument(InstrumentDO* instrumentDO) override
        {
            BankInstrument* bankInstrument = new BankInstrument();
            bankInstrument->instrumentID = rand()%(100-10)+10;
            bankInstrument->bankAccountNumber = instrumentDO->bankAccountNumber;
            bankInstrument->ifscCOde = instrumentDO->ifsc;
            bankInstrument->instrumentType = InstrumentType::BANK;
            bankInstrument->userID = instrumentDO->userID;
            
            // Add to map
            userVsInstruments[bankInstrument->userID].push_back(bankInstrument);
            
            return mapBankInstrumentToInstrumentDO(bankInstrument);
        }

        vector<InstrumentDO*> getInstrumentsByUserID(int userID) override
        {
            vector<InstrumentDO*> userInstrumentsFetched;
            
            if(userVsInstruments.find(userID) != userVsInstruments.end()) 
            {
                vector<Instrument*>& userInstruments = userVsInstruments[userID];
                for(auto instrument : userInstruments)
                {
                    if(instrument->getInstrumentType() == InstrumentType::BANK)
                    {
                        userInstrumentsFetched.push_back(mapBankInstrumentToInstrumentDO(static_cast<BankInstrument*>(instrument)));
                    }
                }
            }
            
            return userInstrumentsFetched;
        }

        InstrumentDO* mapBankInstrumentToInstrumentDO(BankInstrument* bankInstrument)
        {
            InstrumentDO* instrumentDOObj = new InstrumentDO();
            instrumentDOObj->instrumentType = bankInstrument->instrumentType;
            instrumentDOObj->instrumentID = bankInstrument->instrumentID;
            instrumentDOObj->bankAccountNumber = bankInstrument->bankAccountNumber;
            instrumentDOObj->ifsc = bankInstrument->ifscCOde;
            instrumentDOObj->userID = bankInstrument->userID;
            return instrumentDOObj;
        }
};

#endif