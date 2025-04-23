// DIFFERENCE BETWEEN PROXY AND MEDIATOR && OBSERVER AND MEDIATOR
#include "Auction.hpp"
#include "AuctionMediator.hpp"
#include "Bidder.hpp"
#include "Collegue.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    AuctionMediator* auction = new Auction();
    
    Collegue* bidder1 = new Bidder("A",auction);
    Collegue* bidder2 = new Bidder("B",auction);

    bidder1->placeBid(10000);
    bidder2->placeBid(20000);
    bidder1->placeBid(20001);

    return 0;
}