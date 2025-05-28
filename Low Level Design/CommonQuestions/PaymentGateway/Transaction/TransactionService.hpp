#ifndef TRANSACTIONSERVICE_HPP
#define TRANSACTIONSERVICE_HPP

#include "Transaction.hpp"
#include "../Instrument/InstrumentController.hpp"
#include "../Instrument/InstrumentDO.hpp"
#include "Processor.hpp"
#include "TransactionDO.hpp"
#include "TransactionType.hpp"
#include<bits/stdc++.h>
using namespace std;

class TransactionService{
    public:
        static unordered_map<int,vector<Transaction*>> usersVsTransactionsList;
        InstrumentController* instrumentController;
        Processor* processor;

        TransactionService()
        {
            instrumentController = new InstrumentController();
            processor = new Processor();
        }

        vector<Transaction*> getTransactionHistory(int userID)
        {
            if(usersVsTransactionsList.find(userID) != usersVsTransactionsList.end()) {
                return usersVsTransactionsList[userID];
            }
            return vector<Transaction*>();
        }

        TransactionDO* makePayment(TransactionDO* txnDO)
        {
            InstrumentDO* senderIntrumentDO = instrumentController->getInstrumentByID(txnDO->senderUserID,txnDO->debitInstrumentID);
            InstrumentDO* receiverInstrumentDO = instrumentController->getInstrumentByID(txnDO->recieverUserID,txnDO->creditInstrumentID);

            if(senderIntrumentDO == NULL || receiverInstrumentDO == NULL) {
                cout << "Error: Could not find instruments for transaction" << endl;
                return NULL;
            }

            processor->processPayment(senderIntrumentDO,receiverInstrumentDO);

            Transaction* txn = new Transaction();
            txn->Amount = txnDO->Amount;
            txn->txnID = rand()%(100-10)+10;
            txn->senderUserID = txnDO->senderUserID;
            txn->recieverUserID = txnDO->recieverUserID;
            txn->debitInstrumentID = txnDO->debitInstrumentID;
            txn->creditInstrumentID = txnDO->creditInstrumentID;
            txn->status = TransactionType::SUCCESS;

            // Add transaction to sender's list
            usersVsTransactionsList[txn->senderUserID].push_back(txn);
            
            // Add transaction to receiver's list
            usersVsTransactionsList[txn->recieverUserID].push_back(txn);

            txnDO->txnID = txn->txnID;
            txnDO->status = txn->status;
            return txnDO;
        }
};

#endif
