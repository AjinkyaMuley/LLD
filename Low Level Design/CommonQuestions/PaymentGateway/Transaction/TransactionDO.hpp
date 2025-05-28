#ifndef TRANSACTIONDO_HPP
#define TRANSACTIONDO_HPP

#include "TransactionType.hpp"
#include <bits/stdc++.h>
using namespace std;

class TransactionDO
{
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