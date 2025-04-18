#ifndef MBASTUDENTBUILDER_HPP
#define MBASTUDENTBUILDER_HPP

#include "StudentBuilder.hpp"
#include <bits/stdc++.h>
using namespace std;

// class StudentBuilder;


class MBAStudentBuilder : public StudentBuilder{
    public:
        StudentBuilder* setSubjects() override
        {
            vector<string> subs;
            subs.push_back("Marketing");
            subs.push_back("Finance");
            subs.push_back("HR");
            this->subjects = subs;
            return this;
        }
};


#endif