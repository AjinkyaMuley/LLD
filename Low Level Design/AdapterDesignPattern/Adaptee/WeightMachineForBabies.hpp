#ifndef WEIGHTMACHINEFORBABIES_HPP
#define WEIGHTMACHINEFORBABIES_HPP

#include "WeightMachine.hpp"

class WeightMachine;

class WeightMachineForBabies : public WeightMachine{
    public:
        double getWeightInPound() override
        {
            return 28;
        }
};

#endif