#include "./Team/Team.hpp"
#include "./Team/Player/Person.hpp"
#include "./Team/Player/PlayerDetails.hpp"
#include "./Team/Player/PlayerType.hpp"
#include "MatchType.hpp"
#include "T20MatchType.hpp"
#include "Match.hpp"
#include <bits/stdc++.h>
using namespace std;


class PlayerDetails;
class Person;
enum PlayerType;
class Team;
class MatchType;
class T20MatchType;
class Match;

PlayerDetails* addPlayer(string name,PlayerType playerType)
{
    Person* person = new Person();
    person->name = name;
    PlayerDetails* playerDetails = new PlayerDetails(person,playerType);
    return playerDetails;
}


Team* addTeam(string name)
{
    queue<PlayerDetails*> playerDetails = queue<PlayerDetails*>();

    PlayerDetails* p1 = addPlayer(name + "1",PlayerType::ALLROUNDER);
    PlayerDetails* p2 = addPlayer(name + "2",PlayerType::ALLROUNDER);
    PlayerDetails* p3 = addPlayer(name + "3",PlayerType::ALLROUNDER);
    PlayerDetails* p4 = addPlayer(name + "4",PlayerType::ALLROUNDER);
    PlayerDetails* p5 = addPlayer(name + "5",PlayerType::ALLROUNDER);
    PlayerDetails* p6 = addPlayer(name + "6",PlayerType::ALLROUNDER);
    PlayerDetails* p7 = addPlayer(name + "7",PlayerType::ALLROUNDER);
    PlayerDetails* p8 = addPlayer(name + "8",PlayerType::ALLROUNDER);
    PlayerDetails* p9 = addPlayer(name + "9",PlayerType::ALLROUNDER);
    PlayerDetails* p10 = addPlayer(name + "10",PlayerType::ALLROUNDER);
    PlayerDetails* p11 = addPlayer(name + "11",PlayerType::ALLROUNDER);


    playerDetails.push(p1);
    playerDetails.push(p2);
    playerDetails.push(p3);
    playerDetails.push(p4);
    playerDetails.push(p5);
    playerDetails.push(p6);
    playerDetails.push(p7);
    playerDetails.push(p8);
    playerDetails.push(p9);
    playerDetails.push(p10);
    playerDetails.push(p11);


    vector<PlayerDetails*> bowlers = vector<PlayerDetails*>();
    bowlers.push_back(p8);
    bowlers.push_back(p9);
    bowlers.push_back(p10);
    bowlers.push_back(p11);

    vector<PlayerDetails*> bench;
    
    Team* team = new Team(name,playerDetails,bench,bowlers);
    return team;
}


int main()
{

    Team* teamA = addTeam("India");
    Team* teamB = addTeam("SriLanka");

    MatchType* matchType = new T20MatchType();
    
    Match* match = new Match(teamA,teamB,NULL,"SMS Stadium",matchType);
    match->startMatch();
    
    return 0;
}