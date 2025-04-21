#ifndef PLAYERBATTINGCONTROLLER_HPP
#define PLAYERBATTINGCONTROLLER_HPP

#include "PlayerDetails.hpp"
#include <bits/stdc++.h>
using namespace std;

class PlayerDetails;

class PlayerBattingController{
    public:
        queue<PlayerDetails*> yetToPlay;
        PlayerDetails* striker;
        PlayerDetails* nonStriker;

        PlayerBattingController(queue<PlayerDetails*>&  playing11)
        {
            this->yetToPlay = queue<PlayerDetails*>(playing11);
        }

        void getNextPlayer() throw(exception)
        {
            if(yetToPlay.empty())
            {
                throw runtime_error("No players left to play");
            }

            if(striker == nullptr)
            {
                striker = yetToPlay.front();
                yetToPlay.pop();
            }

            if(nonStriker == nullptr)
            {
                nonStriker = yetToPlay.front();
                yetToPlay.pop();
            }
        }

        PlayerDetails* getStriker()
        {
            return striker;
        }

        PlayerDetails* getNonStriker()
        {
            return nonStriker;
        }

        void setStriker(PlayerDetails* player)
        {
            striker = player;
        }

        void setNonStriker(PlayerDetails* player)
        {
            nonStriker = player;
        }
};


#endif