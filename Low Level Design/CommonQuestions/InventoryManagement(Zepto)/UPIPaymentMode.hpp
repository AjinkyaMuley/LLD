#ifndef UPIPAYMENTMODE_HPP
#define UPIPAYMENTMODE_HPP

#include "PaymentMode.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class UPIPaymentMode : public PaymentMode{
    public:
        bool makePayment() override
        {
            return true;
        }
}; 
    
#endif