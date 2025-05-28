#ifndef USER_HPP
#define USER_HPP

#include<bits/stdc++.h>
using namespace std;

class User{
    public:
        int userId;
        string userName;
        string email;

        int getUserID()
        {
            return userId;
        }

        void setUserID(int userID)
        {
            this->userId = userID;
        }

        string getUserName()
        {
            return userName;
        }

        void setUserName(string userName)
        {
            this->userName = userName;
        }

        string getEmail()
        {
            return email;
        }

        void setEmail(string email)
        {
            this->email = email;
        }
};

#endif