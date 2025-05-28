#ifndef INSTRUMENTTYPE
#define INSTRUMENTTYPE

#include "InstrumentType.hpp"
#include<bits/stdc++.h>
using namespace std;

class InstrumentDO{
    public:
        int instrumentID;
        string ifsc;
        string cvv;
        string bankAccountNumber;
        string cardNumber;
        InstrumentType instrumentType;
        int userID;

        int getInstrumentID()
        {
            return instrumentID;
        }

        void setInstrumentID(int instrumentID)
        {
            this->instrumentID = instrumentID;
        }

        string getIfsc()
        {
            return ifsc;
        }

        void setIfsc(const string& ifsc)
        {
            this->ifsc = ifsc;
        }

        string getCvv()
        {
            return cvv;
        }

        void setCvv(const string& cvv)
        {
            this->cvv = cvv;
        }

        string getBankAccountNumber()
        {
            return bankAccountNumber;
        }

        void setBankAccountNumber(const string& bankAccountNumber)
        {
            this->bankAccountNumber = bankAccountNumber;
        }

        string getCardNumber()
        {
            return cardNumber;
        }

        void setCardNumber(const string& cardNumber)
        {
            this->cardNumber = cardNumber;
        }

        InstrumentType getInstrumentType()
        {
            return instrumentType;
        }

        void setInstrumentType(const InstrumentType& instrumentType)
        {
            this->instrumentType = instrumentType;
        }

        int getUserID()
        {
            return userID;
        }

        void setUserID(int userID)
        {
            this->userID = userID;
        }

        
};

#endif