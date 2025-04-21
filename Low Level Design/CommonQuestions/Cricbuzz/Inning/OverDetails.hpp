#ifndef OVERDETAILS_HPP
#define OVERDETAILS_HPP

#include "BallDetails.hpp"
#include "../Team/Player/PlayerDetails.hpp"
#include "../Team/Team.hpp"
#include <bits/stdc++.h>
using namespace std;

class BallDetails;
class PlayerDetails;
class Team;

class OverDetails{
    public:
        int overNumber;
        vector<BallDetails*> balls;
        int extraBallsCount;
        PlayerDetails* bowledBy;


        OverDetails(int overNumber,PlayerDetails* bowledBy)
        {
            this->overNumber = overNumber;
            balls = vector<BallDetails*>();
            this->bowledBy = bowledBy;
        }

        bool startOver(Team* battingTeam,Team* bowlingTeam,int runsToWin) throw(exception)
        {
            int ballCount = 0;

            while(ballCount <= 6)
            {
                BallDetails* ball = new BallDetails(ballCount);
                ball->startBallDelivery(battingTeam,bowlingTeam,this);

                if(ball->ballType == BallType::NORMAL)
                {
                    balls.push_back(ball);
                    ballCount++;

                    if(ball->wicket != NULL)
                    {
                        battingTeam->chooseNextBatsman();
                    }

                    if(runsToWin != -1 && battingTeam->getTotalRuns() >= runsToWin)
                    {
                        battingTeam->isWinner = true;
                        return true;
                    }
                }
                else
                {
                    extraBallsCount++;
                }
            }

            return false;
        }
};


#endif