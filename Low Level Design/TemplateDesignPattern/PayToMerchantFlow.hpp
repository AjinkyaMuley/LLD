#ifndef PAYTOMERCHANTFLOW_HPP
#define PAYTOMERCHANTFLOW_HPP


#include "PaymentFlow.hpp"
#include <bits/stdc++.h>
using namespace std;


class PayToMerchantFlow : public PaymentFlow{
    public:
        void validateRequest() override
        {
            cout << "Validate logic for PayToMerchantFlow" << endl;
        }

        void calculateFees() override
        {
            cout << "2% fees charged" << endl;
        }

        void debitAmount() override
        {
            cout << "Debit the Amount logic of PayToMerchant" << endl;
        }

        void creditAmount() override
        {
            cout << "Credit the remaining amount" << endl;
        }
};


#endif