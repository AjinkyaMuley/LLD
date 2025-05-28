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
    InstrumentController* instrumentController = new InstrumentController();
    UserController* userController = new UserController();
    TransactionController* transactionController = new TransactionController();

    // add USER1
    UserDO* user1 = new UserDO();
    user1->setName("AM");
    user1->setMail("am@gmail.com");
    UserDO* user1Details = userController->addUser(user1);


    // add USER2
    UserDO* user2 = new UserDO();
    user1->setName("PJ");
    user1->setMail("pj@gmail.com");
    UserDO* user2Details = userController->addUser(user2);

    // add bank to User1

    InstrumentDO* bankInstrumentDO = new InstrumentDO();
    bankInstrumentDO->setBankAccountNumber("234324234324324");
    bankInstrumentDO->setInstrumentType(InstrumentType::BANK);
    bankInstrumentDO->setUserID(user1Details->getUserID());
    bankInstrumentDO->setIfsc("ER3223E");
    InstrumentDO* user1BankInstrument = instrumentController->addInstrument(bankInstrumentDO);
    cout << "Bank Instrument created for User1: " << user1BankInstrument->getInstrumentID();

    // add Card to User2

    InstrumentDO* cardInstrumentDO = new InstrumentDO();
    cardInstrumentDO->setCardNumber("1230099");
    cardInstrumentDO->setInstrumentType(InstrumentType::CARD);
    cardInstrumentDO->setCvv("0000");
    cardInstrumentDO->setUserID(user2Details->getUserID());
    InstrumentDO* user2CardInstrument = instrumentController->addInstrument(cardInstrumentDO);
    cout << "Card Instrument created for User2 : " << user2CardInstrument->getInstrumentID();

    // make payment

    TransactionDO* transactionDO = new TransactionDO();
    transactionDO->Amount = 10;
    transactionDO->senderUserID = user1Details->getUserID();
    transactionDO->recieverUserID = user2Details->getUserID();
    transactionDO->debitInstrumentID = user1BankInstrument->getInstrumentID();
    transactionDO->creditInstrumentID = user2CardInstrument->getInstrumentID();
    transactionController->makePayment(transactionDO);

    // get all instruments of USER1

    vector<InstrumentDO*> user1Instruments = instrumentController->getAllInstruments(user1Details->getUserID());
    
    for(auto instrumentDO : user1Instruments)
    {
        cout << "User1 InstID: " << instrumentDO->getInstrumentID() << " : UserID: " << instrumentDO->getUserID() << ": InstrumentType: " << ((instrumentDO->getInstrumentType() == InstrumentType::BANK) ? "Bank" : "Card") << endl;
    }

    // get ALl instruments of user2 

    vector<InstrumentDO*> user2Instruments = instrumentController->getAllInstruments(user2Details->getUserID());

    for(auto instrumentDO : user2Instruments)
    {
        cout << "User2 InstID: " << instrumentDO->getInstrumentID() << " : UserID: " << instrumentDO->getUserID() << " : InstrumentType " << ((instrumentDO->getInstrumentType() == InstrumentType::CARD ? "Card" : "Bank")) << endl;
    }


    return 0;
}