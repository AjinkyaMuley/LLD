#ifndef SPLIT_HPP
#define SPLIT_HPP

#include "../../User/User.hpp"
#include <bits/stdc++.h>
using namespace std;

class User;


class Split{
    public:
        User* user;
        double amountOwe;

        Split(User* user,double amountOwe)
        {
            this->user = user;
            this->amountOwe = amountOwe;
        }

        User* getUser()
        {
            return user;
        }

        void setUser(User* user)
        {
            this->user = user;
        }

        double getAmountOwe()
        {
            return amountOwe;
        }

        void setAmountOwe(double amountOwe)
        {
            this->amountOwe = amountOwe;
        }
};

#endif