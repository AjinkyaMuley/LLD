#ifndef BOWLINGSCOREUPDATER_HPP
#define BOWLINGSCOREUPDATER_HPP

#include "ScoreUpdaterObserver.hpp"
#include "../Inning/BallDetails.hpp"

class BallDetails;
class ScoreUpdaterObserver;

class BowlingScoreUpdater : public ScoreUpdaterObserver{
    public:
        void update(BallDetails* ballDetails) override
        {
            if(ballDetails->ballNumber == 6 && ballDetails->ballType == BallType::NORMAL)
            {
                ballDetails->bowledBy->bowlingScoreCard->totalOversCount++;
            }

            if(RunType::ONE == ballDetails->runType)
            {
                ballDetails->bowledBy->bowlingScoreCard->runsGiven += 1;
            }
            else if(RunType::TWO == ballDetails->runType)
            {
                ballDetails->bowledBy->bowlingScoreCard->runsGiven += 2;
            }
            else if(RunType::THREE == ballDetails->runType)
            {
                ballDetails->bowledBy->bowlingScoreCard->runsGiven += 3;
            }
            else if(RunType::FOUR == ballDetails->runType)
            {
                ballDetails->bowledBy->bowlingScoreCard->runsGiven += 4;
            }
            else if(RunType::SIX == ballDetails->runType)
            {
                ballDetails->bowledBy->bowlingScoreCard->runsGiven += 6;
            }

            if(ballDetails->wicket != NULL)
            {
                ballDetails->bowledBy->bowlingScoreCard->wicketsTaken++;
            }

            if(ballDetails->ballType == BallType::NOBALL)
            {
                ballDetails->bowledBy->bowlingScoreCard->noBallCount++;
            }

            if(ballDetails->ballType == BallType::WIDEBALL)
            {
                ballDetails->bowledBy->bowlingScoreCard->wideBallCount++;
            }
        }
};

#endif