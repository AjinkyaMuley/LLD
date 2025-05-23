#ifndef WAREHOUSESELECTIONSTRATEGY_HPP
#define WAREHOUSESELECTIONSTRATEGY_HPP
    
#include "Warehouse.hpp"
#include<bits/stdc++.h>
using namespace std;
    
class WarehouseSelectionStategy{
    public:
        virtual Warehouse* selectWarehouse(vector<Warehouse*>& warehouseList) = 0;
};

#endif