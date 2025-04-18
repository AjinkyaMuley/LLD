#ifndef ENGINEERINGSTUDENTBUILDER_HPP
#define ENGINEERINGSTUDENTBUILDER_HPP


#include "StudentBuilder.hpp"
#include <bits/stdc++.h>
using namespace std;


// class StudentBuilder;

class EngineeringStudentBuilder : public StudentBuilder{
    public:
        StudentBuilder* setSubjects() override
        {
            vector<string> subs;
            subs.push_back("DSA");
            subs.push_back("OS");
            subs.push_back("DBMS");
            this->subjects = subs;
            return this;
        }
};

#endif