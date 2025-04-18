#include "Student.hpp"
#include "StudentBuilder.hpp"

Student::Student(StudentBuilder* builder)
{
    this->rollNumber = builder->rollNumber;
    this->age = builder->age;
    this->name = builder->name;
    this->fatherName = builder->fatherName;
    this->motherName = builder->motherName;
    this->subjects = builder->subjects;
}