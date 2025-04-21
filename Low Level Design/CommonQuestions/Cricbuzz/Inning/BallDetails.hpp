#ifndef BALLDETAILS_HPP
#define BALLDETAILS_HPP

#include "RunType.hpp"
#include "../Team/Player/PlayerDetails.hpp"
#include "BallType.hpp"
#include "../Team/Wicket.hpp"
#include "../ScoreUpdater/ScoreUpdaterObserver.hpp"
#include "../ScoreUpdater/BattingScoreUpdater.hpp"
#include "../ScoreUpdater/BowlingScoreUpdater.hpp"
#include "../Team/Team.hpp"
#include "OverDetails.hpp"

#include <bits/stdc++.h>
using namespace std;

class PlayerDetails;
class Wicket;
class ScoreUpdaterObserver;
class BattingScoreUpdater;
class BowlingScoreUpdater;
class Team;
class OverDetails;

enum BallType;
enum RunType;

class BallDetails{
    public:
        int ballNumber;
        BallType ballType;
        RunType runType;
        PlayerDetails* playedBy;
        PlayerDetails* bowledBy;
        Wicket* wicket;
        vector<ScoreUpdaterObserver*> scoreUpdaterObserverList;

        BallDetails(int ballNumber)
        {
            this->ballNumber = ballNumber;
            scoreUpdaterObserverList.push_back(new BattingScoreUpdater());
            scoreUpdaterObserverList.push_back(new BowlingScoreUpdater());
            scoreUpdaterObserverList = vector<ScoreUpdaterObserver*>();
        }

        void startBallDelivery(Team* battingTeam,Team* bowlingTeam,OverDetails* over)
        {
            playedBy = battingTeam->getStriker();
            this->bowledBy = over->bowledBy;

            ballType = BallType::NORMAL;

            if(isWicketTaken())
            {
                runType = RunType::ZERO;

                wicket = new Wicket(WicketType::BOLD,bowlingTeam->getCurrentBowler(),over,this);
                battingTeam->setStriker(NULL);
            }
            else
            {
                runType = getRunType();

                if(runType == RunType::ONE || runType == RunType::THREE)
                {
                    PlayerDetails* temp = battingTeam->getStriker();
                    battingTeam->setStriker(battingTeam->getNonStriker());
                    battingTeam->setNonStriker(temp);
                }
            }

            notifyUpdater(this);
        }

    private:
        void notifyUpdater(BallDetails* ballDetails)
        {
            for(auto observer : scoreUpdaterObserverList)
            {
                observer->update(ballDetails);
            }
        }


        RunType getRunType()
        {
            double val = (double)rand()/RAND_MAX;

            if(val <= 0.2)
            {
                return RunType::ONE;
            }
            else if(val >= 0.3 && val <= 0.5)
            {
                return RunType::TWO;
            }
            else if(val >= 0.6 && val <= 0.8)
            {
                return RunType::FOUR;
            }
            else
            {
                return RunType::SIX;
            }
        }

        bool isWicketTaken()
        {
            double val = (double)rand()/RAND_MAX;

            if(val < 0.2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};


#endif