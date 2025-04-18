#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class StudentBuilder;

class Student
{
public:
    int rollNumber;
    int age;
    string name;
    string fatherName;
    string motherName;
    vector<string> subjects;

    // Constructor taking StudentBuilder pointer
    Student(StudentBuilder* builder);

    string toString()
    {
        return "Roll number : " + to_string(this->rollNumber) + " age : " + to_string(this->age) + " name : " + this->name + " father name : " + this->fatherName + " mother name : " + this->motherName + " subjects : " + subjects[0] + ", " + subjects[1] + ", " + subjects[2];
    }
};

#endif