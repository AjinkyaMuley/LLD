#ifndef CART_HPP
#define CART_HPP

#include <bits/stdc++.h>
using namespace std;

class Cart
{
public:
    unordered_map<int, int> productCategoryIdVsCountMap;

    Cart()
    {
        productCategoryIdVsCountMap = unordered_map<int, int>();
    }

    void addItemInCart(int productCategoryId, int count)
    {
        if (productCategoryIdVsCountMap.find(productCategoryId) == productCategoryIdVsCountMap.end())
        {
            productCategoryIdVsCountMap[productCategoryId] = count;
        }
        else
        {
            productCategoryIdVsCountMap[productCategoryId] += count;
        }
    }

    void remoteItemFromCart(int productCategoryId, int count)
    {
        if (productCategoryIdVsCountMap.find(productCategoryId) != productCategoryIdVsCountMap.end())
        {
            productCategoryIdVsCountMap[productCategoryId] -= count;
            if (productCategoryIdVsCountMap[productCategoryId] <= 0)
            {
                productCategoryIdVsCountMap.erase(productCategoryId);
            }
        }
    }

    void emptyCart()
    {
        productCategoryIdVsCountMap.clear();
    }

    unordered_map<int,int> getCartItems()
    {
        return productCategoryIdVsCountMap;
    }
};

#endif