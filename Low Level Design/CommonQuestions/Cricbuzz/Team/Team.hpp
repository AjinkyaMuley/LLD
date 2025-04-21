#ifndef TEAM_HPP
#define TEAM_HPP

#include "./Player/PlayerDetails.hpp"
#include "./Player/PlayerBattingController.hpp"
#include "./Player/PlayerBowlingController.hpp"
#include <bits/stdc++.h>
using namespace std;

class PlayerDetails;
class PlayerBattingController;
class PlayerBowlingController;

class Team{
    public:
        string teamName;
        queue<PlayerDetails*> playing11;
        vector<PlayerDetails*> bench;
        PlayerBattingController* battingController;
        PlayerBowlingController* bowlingController;
        bool isWinner;

        Team(string teamName,queue<PlayerDetails*>& playing11,vector<PlayerDetails*>& bench,vector<PlayerDetails*>& bowlers)
        {
            this->teamName = teamName;
            this->playing11 = playing11;
            this->bench = bench;
            this->battingController = new PlayerBattingController(playing11);
            this->bowlingController = new PlayerBowlingController(bowlers);
        }

        string getTeamName()
        {
            return this->teamName;
        }

        void chooseNextBatsman() throw(exception)
        {
            battingController->getNextPlayer();
        }

        void chooseNextBowler(int maxOverCountPerBowler)
        {
            bowlingController->getNextBowler(maxOverCountPerBowler);
        }

        PlayerDetails* getStriker()
        {
            return battingController->getStriker();
        }

        PlayerDetails* getNonStriker()
        {
            return battingController->getNonStriker();
        }

        void setStriker(PlayerDetails* player)
        {
            battingController->setStriker(player);
        }

        void setNonStriker(PlayerDetails* player)
        {
            battingController->setNonStriker(player);
        }

        PlayerDetails* getCurrentBowler()
        {
            return bowlingController->getCurrentBowler();
        }

        void printBattingScoreCard()
        {
            vector<PlayerDetails*> tempPlaying11;
            queue<PlayerDetails*> tempQueue = playing11;
            while (!tempQueue.empty()) {
                tempPlaying11.push_back(tempQueue.front());
                tempQueue.pop();
            }
            for(PlayerDetails* player : tempPlaying11)
            {
                player->printBattingScoreCard();
            }
        }

        void printBowlingScoreCard()
        {
            vector<PlayerDetails*> tempPlaying11;
            queue<PlayerDetails*> tempQueue = playing11;
        
            while(!tempQueue.empty())
            {
                tempPlaying11.push_back(tempQueue.front());
                tempQueue.pop();
            }

            for(auto player : tempPlaying11)
            {
                if(player->bowlingScoreCard->totalOversCount > 0)
                {
                    player->printBowlingScoreCard();
                }
            }
        }

        int getTotalRuns()
        {
            int totalRuns = 0;

            vector<PlayerDetails*> tempPlaying11;
            queue<PlayerDetails*> tempQueue = playing11;

            while(!tempQueue.empty())
            {
                tempPlaying11.push_back(tempQueue.front());
                tempQueue.pop();
            }

            for(auto player : tempPlaying11)
            {
                totalRuns += player->battingScoreCard->totalRuns;
            }

            return totalRuns;
        }
};

#endif