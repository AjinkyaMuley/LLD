#ifndef STUDENTBUILDER_HPP
#define STUDENTBUILDER_HPP

#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class Student;

class StudentBuilder
{
public:
    int rollNumber;
    int age;
    string name;
    string fatherName;
    string motherName;
    vector<string> subjects;

    StudentBuilder *setRollNumber(int rollNumber)
    {
        this->rollNumber = rollNumber;
        return this;
    }

    StudentBuilder *setAge(int age)
    {
        this->age = age;
        return this;
    }

    StudentBuilder *setName(string name)
    {
        this->name = name;
        return this;
    }

    StudentBuilder *setFatherName(string fatherName)
    {
        this->fatherName = fatherName;
        return this;
    }

    StudentBuilder *setMotherName(string motherName)
    {
        this->motherName = motherName;
        return this;
    }

    virtual StudentBuilder *setSubjects() = 0;

    Student *build();
};

#endif