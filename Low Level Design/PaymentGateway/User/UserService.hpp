#ifndef USERSERVICE_HPP
#define USERSERVICE_HPP

#include "User.hpp"
#include "UserDo.hpp"
#include<bits/stdc++.h>
using namespace std;

class UserService{
    public:
        static vector<User*> usersList;

        UserDO* addUser(UserDO* userDO)
        {
            User* userObj = new User();
            userObj->setUserName(userDO->getName());
            userObj->setEmail(userDO->getMail());
            userObj->setUserID((int)rand()%10000);

            usersList.push_back(userObj);
            return convertUserDOToUser(userObj);
        }

        UserDO* getUser(int userID)
        {
            for(auto user : usersList)
            {
                if(user->getUserID() == userID)
                {
                    return convertUserDOToUser(user);
                }
            }

            return NULL;
        }

        private:
            UserDO* convertUserDOToUser(User* userObj)
            {
                UserDO* userDo = new UserDO();
                userDo->setName(userObj->getUserName());
                userDo->setMail(userObj->getEmail());
                userDo->setUserID(userObj->getUserID());
                return userDo;
            }
};

#endif