#ifndef USER_HPP
#define USER_HPP
    
#include "Address.hpp"
#include "Cart.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class User{
    public:
        int userId;
        string userName;
        Address* address;
        Cart* userCartDetails;
        vector<int> orderIds;

        User()
        {
            userCartDetails = new Cart();
            orderIds = vector<int>();
        }

        Cart* getUserCart()
        {
            return userCartDetails;
        }
};
    
#endif