#ifndef EMPLOYEEFACADE_HPP
#define EMPLOYEEFACADE_HPP

#include "Employee.hpp"
#include "EmployeeDAO.hpp"
#include <bits/stdc++.h>
using namespace std;


class EmployeeFacade{
    
    public:
        EmployeeDAO* employeeDAO;
        EmployeeFacade()
        {
            this->employeeDAO = new EmployeeDAO();
        }    

        void insert()
        {
            employeeDAO->insert();
        }

        void updateEmployeeName(int employeeId)
        {
            employeeDAO->updateEmployeeName(employeeId);
        }

        Employee* getEmployeeDetails(string emailId)
        {
            return employeeDAO->getEmployeeDetails(emailId);
        }
};


#endif