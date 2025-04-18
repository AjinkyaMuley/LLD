#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "StudentBuilder.hpp"
#include "EngineeringStudentBuilder.hpp"
#include "MBAStudentBuilder.hpp"
#include <bits/stdc++.h>
using namespace std;

// class StudentBuilder;
// class EngineeringStudentBuilder;
// class MBAStudentBuilder;

class Director
{

public:
    StudentBuilder *studentBuilder;

    Director(StudentBuilder *studentBuilder)
    {
        this->studentBuilder = studentBuilder;
    }

    Student *createEngineeringStudent()
    {
        return studentBuilder->setRollNumber(1)->setAge(22)->setName("AM")->setSubjects()->build();
    }

    Student *createMBAStudent()
    {
        return studentBuilder->setRollNumber(2)->setAge(24)->setName("AM")->setFatherName("VM")->setMotherName("VVM")->setSubjects()->build();
    }

    Student *createStudent()
    {
        if (dynamic_cast<EngineeringStudentBuilder *>(studentBuilder) != NULL)
        {
            return createEngineeringStudent();
        }
        else if (dynamic_cast<MBAStudentBuilder *>(studentBuilder) != NULL)
        {
            return createMBAStudent();
        }
        return nullptr; // Add fallback return to avoid undefined behavior
    }
};

#endif