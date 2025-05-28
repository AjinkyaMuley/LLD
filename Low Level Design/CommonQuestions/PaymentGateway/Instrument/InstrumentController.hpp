#ifndef INSTRUMENTCONTROLLER_HPP
#define INSTRUMENTCONTROLLER_HPP

#include "InstrumentServiceFactory.hpp"
#include "InstrumentDO.hpp"
#include "InstrumentService.hpp"
#include<bits/stdc++.h>
using namespace std;

class InstrumentController{
    public:
        InstrumentServiceFactory* instrumentControllerFactory;

        InstrumentController()
        {
            this->instrumentControllerFactory = new InstrumentServiceFactory();
        }

        InstrumentDO* addInstrument(InstrumentDO* instrument)
        {
            InstrumentService* instrumentController = instrumentControllerFactory->getInstrumentService(instrument->instrumentType);
            return instrumentController->addInstrument(instrument);
        }

        vector<InstrumentDO*> getAllInstruments(int userID)
        {
            InstrumentService* bankInstrumentController = instrumentControllerFactory->getInstrumentService(InstrumentType::BANK);
            InstrumentService* cardInstrumentController = instrumentControllerFactory->getInstrumentService(InstrumentType::CARD);

            vector<InstrumentDO*> instrumentDOList;
            
            // Get bank instruments
            vector<InstrumentDO*> bankInstruments = bankInstrumentController->getInstrumentsByUserID(userID);
            instrumentDOList.insert(instrumentDOList.end(), bankInstruments.begin(), bankInstruments.end());
            
            // Get card instruments  
            vector<InstrumentDO*> cardInstruments = cardInstrumentController->getInstrumentsByUserID(userID);
            instrumentDOList.insert(instrumentDOList.end(), cardInstruments.begin(), cardInstruments.end());
            
            return instrumentDOList;
        }

        InstrumentDO* getInstrumentByID(int userID, int instrumentID)
        {
            vector<InstrumentDO*> instrumentDOList = getAllInstruments(userID);
            for(auto instrumentDO : instrumentDOList)
            {
                if(instrumentDO->getInstrumentID() == instrumentID)
                {
                    return instrumentDO;
                }
            }
            return NULL;
        }
};

#endif