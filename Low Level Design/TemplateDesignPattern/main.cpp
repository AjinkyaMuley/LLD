#include "PaymentFlow.hpp"
#include "PayToMerchantFlow.hpp"
#include "PayToFriend.hpp"
#include <bits/stdc++.h>
using namespace std;


int main() 
{

    PaymentFlow* payToFriend = new PayToFriend();
    PaymentFlow* payToMerchant = new PayToMerchantFlow();

    payToFriend->sendMoney();
    cout << "----------------------------------------" << endl;
    payToMerchant->sendMoney();

    return 0;
}