#ifndef GROUPCONTROLLER_HPP
#define GROUPCONTROLLER_HPP

#include "Group.hpp"
#include "../User/User.hpp"
#include <bits/stdc++.h>
using namespace std;

class Group;
class User;


class GroupController{
    public:
        vector<Group*> groupList;

        GroupController()
        {
            groupList = vector<Group*>();
        }

        void createNewGroup(string groupId,string groupName,User* user)
        {
            Group* group = new Group();
            group->setGroupId(groupId);
            group->setGroupName(groupName);

            group->addMember(user);
            groupList.push_back(group);
        }

        Group* getGroup(string groupId)
        {
            for(auto group : groupList)
            {
                if(group->getGroupId() == groupId)
                {
                    return group;
                }
            }

            return NULL;
        }
};


#endif