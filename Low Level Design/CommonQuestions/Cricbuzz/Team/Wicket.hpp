#ifndef WICKET_HPP
#define WICKET_HPP

// Removed unnecessary includes
#include "WicketType.hpp"

class PlayerDetails; // Forward declaration
class OverDetails;   // Forward declaration
class BallDetails;   // Forward declaration

class Wicket
{
public:
    WicketType wicketType;
    PlayerDetails *takenBy;
    OverDetails *overDetail;
    BallDetails *ballDetail;

    Wicket(WicketType wicketType, PlayerDetails *takenBy, OverDetails *overDetail, BallDetails *ballDetail)
    {
        this->wicketType = wicketType;
        this->takenBy = takenBy;
        this->overDetail = overDetail;
        this->ballDetail = ballDetail;
    }
};

#endif