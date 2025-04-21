#ifndef SCOREUPDATEROBSERVER_HPP
#define SCOREUPDATEROBSERVER_HPP

#include "../Inning/BallDetails.hpp"

class BallDetails;

class ScoreUpdaterObserver
{
public:
    virtual void update(BallDetails *ballDetails) = 0;
};

#endif