#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include "User.hpp"
#include "UserService.hpp"
#include "UserDo.hpp"
#include<bits/stdc++.h>
using namespace std;

class UserController{
    public:
        UserService* userService;

        UserController()
        {
            userService = new UserService();
        }

        UserDO* addUser(UserDO* userDOObj)
        {
            return userService->addUser(userDOObj);
        }

        UserDO* getUser(int userID)
        {
            return userService->getUser(userID);
        }
};

#endif