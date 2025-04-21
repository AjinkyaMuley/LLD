#ifndef PLAYERDETAILS_HPP
#define PLAYERDETAILS_HPP

#include "Person.hpp"
#include "PlayerType.hpp"
#include "./Score/BattingScoreCard.hpp"
#include "./Score/BowlingScoreCard.hpp"
#include <bits/stdc++.h>
using namespace std;

class Person;
enum PlayerType;
class BattingScoreCard;
class BowlingScoreCard;

class PlayerDetails{
    public:
        Person* person;
        PlayerType playerType;
        BattingScoreCard* battingScoreCard;
        BowlingScoreCard* bowlingScoreCard;

        PlayerDetails(Person* personDetails, PlayerType playerType)
        {
            this->person = personDetails;
            this->playerType = playerType;
            this->battingScoreCard = new BattingScoreCard();
            this->bowlingScoreCard = new BowlingScoreCard();
        }

        void printBattingScoreCard()
        {
            cout << "PlayerName: " << person->name << " -- totalRuns: " << battingScoreCard->totalRuns << " --totalBallsPlayed: " << battingScoreCard->totalBallsPlayed << " -- 4s: " << battingScoreCard->totalFours << " -- 6s: " << battingScoreCard->totalSix << " -- outby: " << ((battingScoreCard->wicketDetails != NULL) ? battingScoreCard->wicketDetails->takenBy->person->name : "notout") << endl;
        }

        void printBowlingScoreCard()
        {
            cout << "PlayerName: " << person->name << " -- totalOversThrown : " << bowlingScoreCard->totalOversCount << " -- totalRunsGiven: " << bowlingScoreCard->runsGiven << " -- WicketsTaken : " << bowlingScoreCard->wicketsTaken << endl;
        }

        ~PlayerDetails()
        {
            delete person;
            delete battingScoreCard;
            delete bowlingScoreCard;
        }
};

#endif