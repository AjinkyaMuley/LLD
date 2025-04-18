#include "StudentBuilder.hpp"
#include "Student.hpp"

Student* StudentBuilder::build()
{
    return new Student(this);
}