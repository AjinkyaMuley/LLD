#ifndef CARDSERVICE_HPP
#define CARDSERVICE_HPP

#include "InstrumentService.hpp"
#include "CardInstrument.hpp"
#include "Instrument.hpp"
#include "InstrumentDO.hpp"
#include "InstrumentType.hpp"
#include<bits/stdc++.h>
using namespace std;

class CardService : public InstrumentService{
    public:
        InstrumentDO* addInstrument(InstrumentDO* instrumentDO) override
        {
            CardInstrument* cardInstrument = new CardInstrument();
            cardInstrument->instrumentID = rand()%(100-10)+10;
            cardInstrument->cardNumber = instrumentDO->cardNumber;
            cardInstrument->cvvNumber = instrumentDO->cvv;
            cardInstrument->instrumentType = InstrumentType::CARD;
            cardInstrument->userID = instrumentDO->userID;

            vector<Instrument*> userInstrumentsList = userVsInstruments[cardInstrument->userID];
            
            if(userInstrumentsList.size() == 0)
            {
                userInstrumentsList = vector<Instrument*>();
                userVsInstruments[cardInstrument->userID] = userInstrumentsList;
            }            

            userInstrumentsList.push_back(cardInstrument);
            return mapCardInstrumentToInstrumentDO(cardInstrument);
        }

        vector<InstrumentDO*> getInstrumentsByUserID(int userID)
        {
            vector<Instrument*> userInstruments = userVsInstruments[userID];
            vector<InstrumentDO*> userInstrumentsFetched = vector<InstrumentDO*>();

            for(auto instrument : userInstruments)
            {
                if(instrument->getInstrumentType() == InstrumentType::CARD)
                {
                    userInstrumentsFetched.push_back(mapCardInstrumentToInstrumentDO(static_cast<CardInstrument*>(instrument)));
                }
            }

            return userInstrumentsFetched;
        }

        InstrumentDO* mapCardInstrumentToInstrumentDO(CardInstrument* cardInstrument)
        {
            InstrumentDO* instrumentDOObj = new InstrumentDO();
            instrumentDOObj->instrumentType = cardInstrument->instrumentType;
            instrumentDOObj->instrumentID = cardInstrument->instrumentID;
            instrumentDOObj->cardNumber = cardInstrument->cardNumber;
            instrumentDOObj->cvv = cardInstrument->cvvNumber;
            instrumentDOObj->userID = cardInstrument->userID;
            return instrumentDOObj;
        }
};

#endif