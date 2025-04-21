#ifndef ONEDAYMATCHTYPE_HPP
#define ONEDAYMATCHTYPE_HPP

#include "MatchType.hpp"

class MatchType;


class OneDayMatchType : public MatchType{
    public:
        int noOfOvers() override
        {
            return 50;
        }

        int maxOverCountBowlers() override
        {
            return 10;
        }
};


#endif