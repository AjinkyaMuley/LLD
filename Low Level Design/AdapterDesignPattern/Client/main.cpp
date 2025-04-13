#include "../Adaptee/WeightMachine.hpp"
#include "../Adapter/WeightMachineAdapter.hpp"
#include "../Adapter/WeightMachineAdapterImpl.hpp"
#include "../Adaptee/WeightMachineForBabies.hpp"
#include<bits/stdc++.h>
using namespace std;

class WeightMachine;
class WeightMachineAdapter;
class WeightMachineAdapterImpl;
class WeightMachineForBabies;

int main()
{
    WeightMachineAdapter* weightMachineAdapter = new WeightMachineAdapterImpl(new WeightMachineForBabies());

    cout << weightMachineAdapter->getWeightInKg() << endl;
    
    return 0;
}