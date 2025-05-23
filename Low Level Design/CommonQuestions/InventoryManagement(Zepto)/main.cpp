#include "Warehouse.hpp"
#include "Inventory.hpp"
#include "Product.hpp"
#include "User.hpp"
#include "Address.hpp"
#include "ProductDeliverySystem.hpp"
#include "ProductCategory.hpp"
#include "Order.hpp"
#include "NearestWarehouseSelectionStrategy.hpp"
#include<bits/stdc++.h>
using namespace std;

Warehouse* addWarehouseAndItsInventory()
{
    Warehouse* warehouse = new Warehouse();
    Inventory* inventory = new Inventory();

    inventory->addCategory(0001,"Pepsi Large Cold Drink",100);
    inventory->addCategory(0004,"Dove Small Soap",50);

    Product* product1 = new Product();
    product1->productId = 1;
    product1->productName = "Pepsi";

    Product* product2 = new Product();
    product2->productId = 2;
    product2->productName = "Pepsi";

    Product* product3 = new Product();
    product2->productId = 3;
    product2->productName = "Dove";

    inventory->addProduct(product1,0001);
    inventory->addProduct(product2,0001);
    inventory->addProduct(product3,0004);

    warehouse->inventory = inventory;
    return warehouse;
}

User* createUser()
{
    User* user = new User();
    user->userId = 1;
    user->userName = "SJ";
    user->address = new Address(230011,"city","state");
    return user;
}

void runDeliveryFlow(ProductDeliverySystem* productDeliverySystem,int userId)
{
    User* user = productDeliverySystem->getUser(userId);

    Warehouse* warehouse = productDeliverySystem->getWarehouse(new NearestWarehouseSelectionStrategy());

    Inventory* inventory = productDeliverySystem->getInventory(warehouse);

    ProductCategory* productCategoryIWantToOrder = NULL;
    for(auto productCategory : inventory->productCategoryList)
    {
        if(productCategory->categoryName == "Pepsi Large Cold Drink")
        {
            productCategoryIWantToOrder = productCategory;
            break;
        }
    }

    productDeliverySystem->addProductToCart(user,productCategoryIWantToOrder,2);

    Order* order = productDeliverySystem->placeOrder(user,warehouse);

    productDeliverySystem->checkout(order);
}


int main()
{
    vector<Warehouse*> warehouseList;
    warehouseList.push_back(addWarehouseAndItsInventory());

    vector<User*> userList;
    userList.push_back(createUser());

    ProductDeliverySystem* productDeliverySystem = new ProductDeliverySystem(userList,warehouseList);

    runDeliveryFlow(productDeliverySystem,1);

    return 0;
}