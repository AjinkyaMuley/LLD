#ifndef BATTINGSCOREUPDATER_HPP
#define BATTINGSCOREUPDATER_HPP


#include "ScoreUpdaterObserver.hpp"
#include "../Inning/BallDetails.hpp"
#include "../Inning/RunType.hpp"

enum RunType;
class BallDetails;
class ScoreUpdaterObserver;


class BattingScoreUpdater : public ScoreUpdaterObserver{
    public:
        void update(BallDetails* ballDetails) override
        {
            int run = 0;

            if(RunType::ONE == ballDetails->runType)
            {
                run = 1;
            }
            else if(RunType::TWO == ballDetails->runType)
            {
                run = 2;
            }
            else if(RunType::THREE == ballDetails->runType)
            {
                run = 3;
            }
            else if(RunType::FOUR == ballDetails->runType)
            {
                run = 4;
                ballDetails->playedBy->battingScoreCard->totalFours++;
            }
            else if(RunType::SIX == ballDetails->runType)
            {
                run = 6;
                ballDetails->playedBy->battingScoreCard->totalSix++;
            }

            ballDetails->playedBy->battingScoreCard->totalRuns += run;

            ballDetails->playedBy->battingScoreCard->totalBallsPlayed++;

            if(ballDetails->wicket != NULL)
            {
                ballDetails->playedBy->battingScoreCard->wicketDetails = ballDetails->wicket;
            }
        }
};


#endif