#include <bits/stdc++.h>
using namespace std;

class EmployeeDo
{
public:
    int employeeId;
    string name;
    string email;
};


class EmployeeDao
{
public:
    virtual void create(string client, EmployeeDo *obj) throw(exception) = 0;
    virtual void deleteEmployee(string client, int employeeId) throw(exception) = 0;
    virtual EmployeeDo *get(string client, int employeeId) throw(exception) = 0;
};

class EmlpoyeeDaoImpl : public EmployeeDao
{
public:
    void create(string client, EmployeeDo *obj) throw(exception) override
    {
        cout << "created new row in the Employee table" << endl;
    }

    void deleteEmployee(string client, int employeeId) throw(exception) override
    {
        cout << "deleted row with employeeId: " << employeeId << endl;
    }

    EmployeeDo *get(string client, int employeeId) throw(exception) override
    {
        cout << "fetching data from DB " << endl;
        return new EmployeeDo();
    }
};


class EmployeeDaoProxy : public EmployeeDao
{
public:
    EmployeeDao *employeeDaoObj;

    EmployeeDaoProxy()
    {
        employeeDaoObj = new EmlpoyeeDaoImpl();
    }

    void create(string client, EmployeeDo *obj) throw(exception) override
    {
        if (client == "ADMIN")
        {
            employeeDaoObj->create(client, obj);
            return;
        }

        throw std::runtime_error("Access Denied");
    }

    void deleteEmployee(string client, int employeeId) throw(exception) override
    {
        if (client == "ADMIN")
        {
            employeeDaoObj->deleteEmployee(client, employeeId);
            return;
        }

        throw std::runtime_error("Access Denied");
    }

    EmployeeDo *get(string client, int employeeId) throw(exception) override
    {
        if (client == "ADMIN")
        {
            return employeeDaoObj->get(client, employeeId);
        }

        throw std::runtime_error("Access Denied");
    }
};

int main()
{
    try
    {
        EmployeeDao* empTableObj = new EmployeeDaoProxy();
        empTableObj->create("ADMIN",new EmployeeDo());
        cout << "Operation successful " << endl;
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    
}