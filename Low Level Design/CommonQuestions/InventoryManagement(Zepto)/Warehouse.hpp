#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Inventory.hpp"
#include "Address.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class Warehouse{
    public:
        Inventory* inventory;
        Address* address;

        void removeItemFromInventory(unordered_map<int,int> productCaqtegoryAndCountMap)
        {
            inventory->removeItems(productCaqtegoryAndCountMap);
        }

        void addItemToInventory(unordered_map<int,int> productCategoryAndCountMap)
        {
            
        }
};

    
#endif