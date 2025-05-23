#ifndef NEARESTWAREHOUSESELECTIONSTRATEGY_HPP
#define NEARESTWAREHOUSESELECTIONSTRATEGY_HPP

#include "WarehouseSelectionStrategy.hpp"
#include<bits/stdc++.h>
using namespace std;

class NearestWarehouseSelectionStrategy : public WarehouseSelectionStategy{
    public:
        Warehouse* selectWarehouse(vector<Warehouse*>& warehouseList) override
        {
            return warehouseList[0];
        }
};
    

#endif