#ifndef TRANSACTIONCONTROLLER_HPP
#define TRANSACTIONCONTROLLER_HPP

#include "TransactionService.hpp"
#include "TransactionDO.hpp"
#include "Transaction.hpp"
#include<bits/stdc++.h>
using namespace std;

class TransactionController{
    public:
        TransactionService* txnService;

        TransactionController()
        {
            txnService = new TransactionService();
        }

        TransactionDO* makePayment(TransactionDO* txnDO)
        {
            return txnService->makePayment(txnDO);
        }

        vector<Transaction*> getTransactionHistory(int userID)
        {
            return txnService->getTransactionHistory(userID);
        }
};

#endif