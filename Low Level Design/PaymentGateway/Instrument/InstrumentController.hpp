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

            vector<InstrumentDO*> instrumentDOList = bankInstrumentController->getInstrumentsByUserID(userID);

            instrumentDOList.insert(instrumentDOList.end(), 
                cardInstrumentController->getInstrumentsByUserID(userID).begin(), 
                cardInstrumentController->getInstrumentsByUserID(userID).end());
            return instrumentDOList;
        }

        InstrumentDO* getInstrumentByID(int userID,int instrumentiD)
        {
            vector<InstrumentDO*> instrumentDOList = getAllInstruments(userID);
            for(auto instrumentDO : instrumentDOList)
            {
                if(instrumentDO->getInstrumentID() == instrumentiD)
                {
                    return instrumentDO;
                }
            }
            return NULL;
        }

};

#endif