#ifndef AUCTION_HPP
#define AUCTION_HPP

#include "AuctionMediator.hpp"
#include "Collegue.hpp"
#include <bits/stdc++.h>
using namespace std;


class Auction : public AuctionMediator{
        vector<Collegue*> collegues;

        public:
            Auction()
            {
                this->collegues = vector<Collegue*>();
            }

            void addBidder(Collegue* bidder) override
            {
                collegues.push_back(bidder);
            }

            void placeBid(Collegue* bidder,int amount) override
            {
                for(auto collegue : collegues)
                {
                    if(!collegue->getName().compare(bidder->getName()))
                    {
                        collegue->recieveBidNotification(amount);
                    }
                }
            }
};


#endif