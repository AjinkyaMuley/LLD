#ifndef AUCTIONMEDIATOR_HPP
#define AUCTIONMEDIATOR_HPP

#include "Collegue.hpp"

class AuctionMediator{
    public:
        virtual void addBidder(Collegue* bidder) = 0;
        virtual void placeBid(Collegue* bidder, int amount) = 0;
};


#endif