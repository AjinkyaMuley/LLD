#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include "PaymentMode.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class Payment{
    public:
        PaymentMode* paymentMode;

        Payment(PaymentMode* paymentMode)
        {
            this->paymentMode = paymentMode;
        }

        bool makePayment()
        {
            return paymentMode->makePayment();
        }
};
    
#endif