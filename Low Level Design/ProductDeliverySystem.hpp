#ifndef PRODUCTDELIVERYSYSTEM_HPP
#define PRODUCTDELIVERYSYSTEM_HPP

#include "UserController.hpp"
#include "WarehouseController.hpp"
#include "OrderController.hpp"
#include "WarehouseSelectionStrategy.hpp"
#include "Order.hpp"
#include "Inventory.hpp"
#include "User.hpp"
#include "Warehouse.hpp"
#include "ProductCategory.hpp"
#include "Product.hpp"
#include "Cart.hpp"
#include<bits/stdc++.h>
using namespace std;
    
class ProductDeliverySystem{
    public:
        UserController* userController;
        WarehouseController* warehouseController;
        OrderController* orderController;
        
        ProductDeliverySystem(vector<User*>& userList,vector<Warehouse*>& warehouseList)
        {
            userController = new UserController(userList);
            warehouseController = new WarehouseController(warehouseList,NULL);
            orderController = new OrderController();
        }

        User* getUser(int userId)
        {
            return userController->getUser(userId);
        }

        Warehouse* getWarehouse(WarehouseSelectionStategy* warehouseSelectionStrategy)
        {
            return warehouseController->selectWarehouse(warehouseSelectionStrategy);
        }

        Inventory* getInventory(Warehouse* warehouse)
        {
            return warehouse->inventory;
        }

        void addProductToCart(User* user,ProductCategory* product,int count)
        {
            Cart* cart = user->getUserCart();
            cart->addItemInCart(product->productCategoryId,count);
        }

        Order* placeOrder(User* user,Warehouse* warehouse)
        {
            return orderController->createNewOrder(user,warehouse);
        }

        void checkout(Order* order)
        {
            order->checkout();
        }
};

#endif