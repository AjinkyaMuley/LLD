#ifndef ORDERCONTROLLER_HPP
#define ORDERCONTROLLER_HPP

#include "Order.hpp"
#include "User.hpp"
#include "Warehouse.hpp"
#include<bits/stdc++.h>
using namespace std;
    
class OrderController{
    public:
        vector<Order*> orderList;
        unordered_map<int,vector<Order*>> userIDVsOrders;

        OrderController()
        {
            orderList = vector<Order*>();
            userIDVsOrders = unordered_map<int,vector<Order*>>();
        }

        Order* createNewOrder(User* user,Warehouse* warehouse)
        {
            Order* order = new Order(user,warehouse);
            orderList.push_back(order);

            if(userIDVsOrders.find(user->userId) != userIDVsOrders.end())
            {
                vector<Order*> userOrders = userIDVsOrders[user->userId];
                userOrders.push_back(order);
                userIDVsOrders[user->userId] = userOrders;
            }
            else
            {
                vector<Order*> userOrders = vector<Order*>();
                userOrders.push_back(order);
                userIDVsOrders[user->userId] = userOrders;
            }
            return order;
        }

        void removeOrder(Order* order)
        {

        }

        vector<Order*> getOrderByCustomerId(int userId)
        {
            return {};
        }

        Order* getOrderByOrderId(int orderId)
        {
            return NULL;
        }
};

#endif