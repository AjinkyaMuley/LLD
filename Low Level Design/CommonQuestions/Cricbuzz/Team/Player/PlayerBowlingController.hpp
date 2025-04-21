#ifndef PLAYERBOWLINGCONTROLLER_HPP
#define PLAYERBOWLINGCONTROLLER_HPP


#include "PlayerDetails.hpp"
#include <bits/stdc++.h>
using namespace std;


class PlayerDetails;

class PlayerBowlingController{
    public:
        deque<PlayerDetails*> bowlersList;
        unordered_map<PlayerDetails*,int> bowlerVsOverCount;
        PlayerDetails* currentBowler;

        PlayerBowlingController(vector<PlayerDetails*> bowlers)
        {
            this->bowlersList = deque<PlayerDetails*>();
            this->bowlerVsOverCount = unordered_map<PlayerDetails*,int>();

            for(auto bowler : bowlers)
            {
                this->bowlersList.push_back(bowler);
                this->bowlerVsOverCount[bowler] = 0;
            }
        }

        void getNextBowler(int maxOverCountPerBowler)
        {
            PlayerDetails* playerDetails = this->bowlersList.front();
            this->bowlersList.pop_front();

            if(bowlerVsOverCount[playerDetails] + 1 == maxOverCountPerBowler)
            {
                currentBowler = playerDetails;
            }
            else
            {
                currentBowler = playerDetails;
                bowlersList.push_back(playerDetails);
                bowlerVsOverCount[playerDetails] += 1;
            }
        }

        PlayerDetails* getCurrentBowler()
        {
            return this->currentBowler;
        }
};


#endif