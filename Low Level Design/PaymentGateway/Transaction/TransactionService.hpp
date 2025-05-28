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
            return usersVsTransactionsList[userID];
        }

        TransactionDO* makePayment(TransactionDO* txnDO)
        {
            InstrumentDO* senderIntrumentDO = instrumentController->getInstrumentByID(txnDO->senderUserID,txnDO->debitInstrumentID);
            InstrumentDO* receiverInstrumentDO = instrumentController->getInstrumentByID(txnDO->recieverUserID,txnDO->creditInstrumentID);

            processor->processPayment(senderIntrumentDO,receiverInstrumentDO);

            Transaction* txn = new Transaction();
            txn->Amount = txnDO->Amount;
            txn->txnID = rand()%(100-10)+10;
            txn->senderUserID = txnDO->senderUserID;
            txn->recieverUserID = txnDO->recieverUserID;
            txn->debitInstrumentID = txnDO->debitInstrumentID;
            txn->creditInstrumentID = txnDO->creditInstrumentID;
            txn->status = TransactionType::SUCCESS;

            vector<Transaction*> senderTxnsList = usersVsTransactionsList[txn->senderUserID];

            if(senderTxnsList.size() == 0)
            {
                senderTxnsList = vector<Transaction*>();
                usersVsTransactionsList[txn->senderUserID] = senderTxnsList;
            }

            senderTxnsList.push_back(txn);

            vector<Transaction*> receiverTxnLists = usersVsTransactionsList[txn->recieverUserID];

            if(receiverTxnLists.size() == 0)
            {
                receiverTxnLists = vector<Transaction*>();
                usersVsTransactionsList[txn->recieverUserID] = receiverTxnLists;
            }

            receiverTxnLists.push_back(txn);
            txnDO->txnID = txn->txnID;
            txnDO->status = txn->status;
            return txnDO;
        }
};

#endif