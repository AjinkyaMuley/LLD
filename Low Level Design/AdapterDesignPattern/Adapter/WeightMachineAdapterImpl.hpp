#ifndef WEIGHTMACHINEADAPTERIMPL_HPP
#define WEIGHTMACHINEADAPTERIMPL_HPP

#include "../Adaptee/WeightMachine.hpp"
#include "WeightMachineAdapter.hpp"

class WeightMachineAdapter;
class WeightMachine;

class WeightMachineAdapterImpl : public WeightMachineAdapter{
    public:
        WeightMachine* weightMachine;

        WeightMachineAdapterImpl(WeightMachine* weightMachine)
        {
            this->weightMachine = weightMachine;
        }

        double getWeightInKg() override
        {
            double weightInPound = weightMachine->getWeightInPound();

            return weightInPound * 0.45;
        }
};


#endif