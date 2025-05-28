#ifndef USERDO_HPP
#define USERDO_HPP

#include<bits/stdc++.h>
using namespace std;

class UserDO{
    public:
        int userId;
        string name;
        string mail;

        int getUserID()
        {
            return userId;
        }

        void setUserID(int id)
        {
            userId = id;
        }

        string getName()
        {
            return name;
        }

        void setName(const string& n)
        {
            name = n;
        }

        string getMail()
        {
            return mail;
        }

        void setMail(const string& m)
        {
            mail = m;
        }
};

#endif