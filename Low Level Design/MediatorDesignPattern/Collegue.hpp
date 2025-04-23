#ifndef COLLEGUE_HPP
#define COLLEGUE_HPP

#include <bits/stdc++.h>
using namespace std;

class Collegue{
    public:
        virtual void placeBid(int amount) = 0;
        virtual void recieveBidNotification(int bidAmount) = 0;
        virtual string getName() = 0;
};


#endif