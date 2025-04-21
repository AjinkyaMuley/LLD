#ifndef T20MATCHTYPE_HPP
#define T20MATCHTYPE_HPP

#include "MatchType.hpp"


class MatchType;

class T20MatchType : public MatchType{
    public:
        int noOfOvers() override
        {
            return 20;
        }

        int maxOverCountBowlers() override
        {
            return 5;
        }
};

#endif