#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "TransactionType.hpp"
#include<bits/stdc++.h>
using namespace std;

class Transaction{
    public:
        int txnID;
        int Amount;
        int senderUserID;
        int recieverUserID;
        int debitInstrumentID;
        int creditInstrumentID;
        TransactionType status;
};

#endif