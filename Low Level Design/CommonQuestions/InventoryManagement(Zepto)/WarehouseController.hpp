#ifndef WAREHOUSECONTROLLER_HPP
#define WAREHOUSECONTROLLER_HPP

#include "Warehouse.hpp"
#include "WarehouseSelectionStrategy.hpp"
#include<bits/stdc++.h>
using namespace std;

class WarehouseController{
    public:
        vector<Warehouse*> warehouseList;
        WarehouseSelectionStategy* warehouseSelectionStategy = NULL;

        WarehouseController(vector<Warehouse*>& warehouseList,WarehouseSelectionStategy* warehouseSelectionStategy)
        {
            this->warehouseList = warehouseList;
            this->warehouseSelectionStategy = warehouseSelectionStategy;
        }

        void addNewWarehouse(Warehouse* warehouse)
        {
            warehouseList.push_back(warehouse);
        }

        void removeWarehouse(Warehouse* warehouse)
        {
            warehouseList.erase(remove(warehouseList.begin(), warehouseList.end(), warehouse), warehouseList.end());
        }

        Warehouse* selectWarehouse(WarehouseSelectionStategy* selectionStrategy)
        {
            this->warehouseSelectionStategy = selectionStrategy;
            return warehouseSelectionStategy->selectWarehouse(warehouseList);
        }
};

#endif