#ifndef INNINGSDETAILS_HPP
#define INNINGSDETAILS_HPP

#include "../Team/Team.hpp"
#include "../MatchType.hpp"
#include "OverDetails.hpp"
#include <bits/stdc++.h>
using namespace std;

class Team;
class MatchType;
class OverDetails;


class InningDetails{
    public:
        Team* battingTeam;
        Team* bowlingTeam;
        MatchType* matchType;
        vector<OverDetails*> overs;

        InningDetails(Team* battingTeam,Team* bowlingTeam,MatchType* matchType)
        {
            this->battingTeam = battingTeam;
            this->bowlingTeam = bowlingTeam;
            this->matchType = matchType;
            overs = vector<OverDetails*>();
        }

        void start(int runsToWin)
        {
            try
            {
                battingTeam->chooseNextBatsman();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            int noOfOvers = matchType->noOfOvers();
            for(int overNumber=1;overNumber<=noOfOvers;overNumber++)
            {
                bowlingTeam->chooseNextBowler(matchType->maxOverCountBowlers());

                OverDetails* over = new OverDetails(overNumber,bowlingTeam->getCurrentBowler());
                overs.push_back(over);

                try
                {
                    bool won = over->startOver(battingTeam,bowlingTeam,runsToWin);
                    if(won == true)
                    {
                        break;
                    }
                }
                catch(const std::exception& e)
                {
                    break;
                }

                PlayerDetails* temp = battingTeam->getStriker();
                battingTeam->setStriker(battingTeam->getNonStriker());
                battingTeam->setNonStriker(temp);                
            }            
        }

        int getTotalRuns()
        {
            return battingTeam->getTotalRuns();
        }
};



#endif