// StaticMemberDefinitions.cpp
// This file contains the definitions of all static member variables

#include "Instrument/InstrumentService.hpp"
#include "User/UserService.hpp"
#include "Transaction/TransactionService.hpp"

// Definition of static member variables
unordered_map<int, vector<Instrument*>> InstrumentService::userVsInstruments;
vector<User*> UserService::usersList;
unordered_map<int, vector<Transaction*>> TransactionService::usersVsTransactionsList;