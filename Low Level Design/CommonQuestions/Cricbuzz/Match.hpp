#ifndef MATCH_HPP
#define MATCH_HPP

#include "./Team/Team.hpp"
#include "./Inning/InningDetails.hpp"
#include "MatchType.hpp"
#include <bits/stdc++.h>
using namespace std;

class Team;
class InningDetails;
class MatchType;

class Match{
    public:
        Team* teamA;
        Team* teamB;
        string date;
        string venue;
        Team* tossWinner;
        vector<InningDetails*> innings;
        MatchType* matchType;

        Match(Team* teamA,Team* teamB,string date,string venue,MatchType* matchType)
        {
            this->teamA = teamA;
            this->teamB = teamB;
            this->date = date;
            this->venue = venue;
            this->matchType = matchType;
            innings = vector<InningDetails*>(2);
        }

        void startMatch()
        {
            tossWinner = toss(teamA,teamB);

            for(int inning=1;inning<=2;inning++)
            {
                InningDetails* inningDetails;
                Team* bowlingTeam;
                Team* battingTeam;

                bool isChasing = false;

                if(inning == 1)
                {
                    battingTeam = tossWinner;
                    bowlingTeam = tossWinner->getTeamName() == teamA->getTeamName() ? teamB : teamA;
                    inningDetails = new InningDetails(battingTeam,bowlingTeam,matchType);
                    inningDetails->start(-1);
                }
                else
                {
                    battingTeam = tossWinner;
                    battingTeam = tossWinner->getTeamName() == teamA->getTeamName() ? teamB : teamA;

                    inningDetails = new InningDetails(battingTeam,bowlingTeam,matchType);
                    inningDetails->start(innings[0]->getTotalRuns());

                    if(bowlingTeam->getTotalRuns() > battingTeam->getTotalRuns())
                    {
                        bowlingTeam->isWinner = true;
                    }
                }

                innings[inning-1] = inningDetails;

                cout << endl << "INNING " << inning << " --- total Runs : " << battingTeam->getTotalRuns() << endl << " --- Batting ScoreCard : " << battingTeam->teamName << " ------ " << endl;

                battingTeam->printBattingScoreCard();

                cout << endl << " --- Bowling ScoreCard : " << bowlingTeam->teamName << " ---- " << endl;

                bowlingTeam->printBowlingScoreCard();
            }

            if(teamA->isWinner)
            {
                cout << endl << " -----  WINNER ----- " << teamA->teamName << endl;
            }
            else
            {
                cout << endl << " -----  WINNER ----- " << teamB->teamName << endl;
            }
        }


        private:
            Team* toss(Team* teamA,Team* teamB)
            {
                double val = rand()/RAND_MAX;

                if(val < 0.5)
                {
                    return teamA; 
                }
                else
                {
                    return teamB;
                }
            }
};


#endif