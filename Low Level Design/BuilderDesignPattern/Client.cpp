#include "Director.hpp"
#include "EngineeringStudentBuilder.hpp"
#include "MBAStudentBuilder.hpp"
#include "Student.hpp"
#include<bits/stdc++.h>
using namespace std;


int main()
{

    Director* directorObj1 = new Director(new EngineeringStudentBuilder());
    Director* directorObj2 = new Director(new MBAStudentBuilder());

    Student* engineerStudent = directorObj1->createStudent();
    Student* mbaStudent = directorObj2->createStudent();

    cout << engineerStudent->toString() << endl;
    cout << mbaStudent->toString() << endl;

    

    return 0;
}