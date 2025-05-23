#ifndef CARDPAYMENTMODE_HPP
#define CARDPAYMENTMODE_HPP

#include "PaymentMode.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class CardPaymentMode : public PaymentMode{
    public:
        bool makePayment() override
        {
            return true;
        }
};
    
#endif