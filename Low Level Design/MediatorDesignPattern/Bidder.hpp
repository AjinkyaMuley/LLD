#ifndef BIDDER_HPP
#define BIDDER_HPP


#include "Collegue.hpp"
#include "AuctionMediator.hpp"
#include <bits/stdc++.h>
using namespace std;

class Bidder : public Collegue{
    string name;
    AuctionMediator* auctionMediator;


    public:
        Bidder(string name,AuctionMediator* auctionMediator)
        {
            this->name = name;
            this->auctionMediator = auctionMediator;
            auctionMediator->addBidder(this);
        }

        void placeBid(int amount) override
        {
            auctionMediator->placeBid(this,amount);
        }

        void recieveBidNotification(int bidAmount) override
        {
            cout << "Bidder " << name << " has been notified of a new bid of $ " << bidAmount << endl;
        }

        string getName() override
        {
            return name; 
        }
};


#endif