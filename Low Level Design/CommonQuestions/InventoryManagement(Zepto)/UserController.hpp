#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include "User.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class UserController{
    public:
        vector<User*> userList;

        UserController(vector<User*> userList)
        {
            this->userList = userList;
        }

        void addUser(User* user)
        {
            userList.push_back(user);
        }

        void removeUser(User* user)
        {
            userList.erase(remove(userList.begin(), userList.end(), user), userList.end());
        }

        User* getUser(int userId)
        {
            for(auto user : userList)
            {
                if(user->userId == userId)
                {
                    return user;
                }
            }

            return NULL;
        }
};
    
#endif