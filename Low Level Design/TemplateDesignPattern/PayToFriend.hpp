#ifndef PAYTOFRIEND_HPP
#define PAYTOFRIEND_HPP


#include "PaymentFlow.hpp"
#include <bits/stdc++.h>
using namespace std;


class PayToFriend : public PaymentFlow{
    public:
        void validateRequest() override
        {
            cout << "Validate logic for PayToFriend " << endl;
        }

        void calculateFees() override
        {
            cout << "0% fees charged" << endl;
        }

        void debitAmount() override
        {
            cout << "Debit the Amount logic of PayToFriend" << endl;
        }

        void creditAmount() override
        {
            cout << "Credit the full Amount" << endl;
        }
};


#endif