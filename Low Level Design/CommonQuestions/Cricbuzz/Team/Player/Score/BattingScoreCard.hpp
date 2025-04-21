#ifndef BATTINGSCORECARD_HPP
#define BATTINGSCOREcARD_HPP


#include "../../Wicket.hpp"
class Wicket;

class BattingScoreCard{
    public:
        int totalRuns;
        int totalBallsPlayed;
        int totalFours;
        int totalSix;
        double strikeRate;
        Wicket* wicketDetails;
};


#endif