#include "./Instrument/InstrumentController.hpp"
#include "./Instrument/InstrumentType.hpp"
#include "./User/UserController.hpp"
#include "./Transaction/TransactionController.hpp"
#include "./User/UserDo.hpp"
#include "./Instrument/InstrumentDO.hpp"
#include "./Transaction/TransactionDO.hpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Starting Payment Gateway..." << endl;
    
    InstrumentController* instrumentController = new InstrumentController();
    UserController* userController = new UserController();
    TransactionController* transactionController = new TransactionController();

    // add USER1
    UserDO* user1 = new UserDO();
    user1->setName("AM");
    user1->setMail("am@gmail.com");
    UserDO* user1Details = userController->addUser(user1);
    cout << "User1 created with ID: " << user1Details->getUserID() << endl;

    // add USER2
    UserDO* user2 = new UserDO();
    user2->setName("PJ");
    user2->setMail("pj@gmail.com");
    UserDO* user2Details = userController->addUser(user2);
    cout << "User2 created with ID: " << user2Details->getUserID() << endl;

    // add bank to User1
    InstrumentDO* bankInstrumentDO = new InstrumentDO();
    bankInstrumentDO->setBankAccountNumber("234324234324324");
    bankInstrumentDO->setInstrumentType(InstrumentType::BANK);
    bankInstrumentDO->setUserID(user1Details->getUserID());
    bankInstrumentDO->setIfsc("ER3223E");
    InstrumentDO* user1BankInstrument = instrumentController->addInstrument(bankInstrumentDO);
    cout << "Bank Instrument created for User1: " << user1BankInstrument->getInstrumentID() << endl;

    // add Card to User2
    InstrumentDO* cardInstrumentDO = new InstrumentDO();
    cardInstrumentDO->setCardNumber("1230099");
    cardInstrumentDO->setInstrumentType(InstrumentType::CARD);
    cardInstrumentDO->setCvv("0000");
    cardInstrumentDO->setUserID(user2Details->getUserID());
    InstrumentDO* user2CardInstrument = instrumentController->addInstrument(cardInstrumentDO);
    cout << "Card Instrument created for User2: " << user2CardInstrument->getInstrumentID() << endl;

    // make payment
    TransactionDO* transactionDO = new TransactionDO();
    transactionDO->Amount = 10;
    transactionDO->senderUserID = user1Details->getUserID();
    transactionDO->recieverUserID = user2Details->getUserID();
    transactionDO->debitInstrumentID = user1BankInstrument->getInstrumentID();
    transactionDO->creditInstrumentID = user2CardInstrument->getInstrumentID();
    
    TransactionDO* result = transactionController->makePayment(transactionDO);
    if(result != NULL) {
        cout << "Payment processed with transaction ID: " << result->txnID << endl;
    } else {
        cout << "Payment failed!" << endl;
    }

    // get all instruments of USER1
    cout << "\nGetting User1 instruments..." << endl;
    vector<InstrumentDO*> user1Instruments = instrumentController->getAllInstruments(user1Details->getUserID());
    
    cout << "User1 Instruments:" << endl;
    for(auto instrumentDO : user1Instruments)
    {
        cout << "User1 InstID: " << instrumentDO->getInstrumentID() 
             << " : UserID: " << instrumentDO->getUserID() 
             << " : InstrumentType: " << ((instrumentDO->getInstrumentType() == InstrumentType::BANK) ? "Bank" : "Card") << endl;
    }

    // get all instruments of user2 
    cout << "\nGetting User2 instruments..." << endl;
    vector<InstrumentDO*> user2Instruments = instrumentController->getAllInstruments(user2Details->getUserID());

    cout << "User2 Instruments:" << endl;
    for(auto instrumentDO : user2Instruments)
    {
        cout << "User2 InstID: " << instrumentDO->getInstrumentID() 
             << " : UserID: " << instrumentDO->getUserID() 
             << " : InstrumentType: " << ((instrumentDO->getInstrumentType() == InstrumentType::CARD) ? "Card" : "Bank") << endl;
    }

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}