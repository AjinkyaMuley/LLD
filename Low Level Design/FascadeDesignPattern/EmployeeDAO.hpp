#ifndef EMPLOYEEDAO_HPP
#define EMPLOYEEDAO_HPP

#include "Employee.hpp"
#include <bits/stdc++.h>
using namespace std;


class EmployeeDAO{
    public:
        void insert()
        {
            // insert into Employee Table
        }

        void updateEmployeeName(int employeeId)
        {
            // find and update Employee Name
        }

        Employee* getEmployeeDetails(string emailId)
        {
            // find Employee
            return new Employee();
        }
};


#endif