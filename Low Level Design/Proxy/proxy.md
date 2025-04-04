# 🚀 Chain of Responsibility Pattern in C++

This project demonstrates the **Chain of Responsibility** pattern using a proxy-based implementation for access control to an Employee Data Access Object (DAO).

---

## 🧠 What is Chain of Responsibility?

Chain of Responsibility is a behavioral design pattern that lets you **pass requests along a chain of handlers**. Upon receiving a request, each handler decides either to process it or to pass it to the next handler in the chain.

> ✅ It's great for decoupling sender and receiver of requests.

---

## 📦 Project Structure

### Classes Used

| Class              | Role                                                                 |
|--------------------|----------------------------------------------------------------------|
| `EmployeeDo`        | Data Transfer Object (DTO) for employee details                      |
| `EmployeeDao`       | Interface (abstract class) defining data operations                  |
| `EmployeeDaoImpl`   | Real handler that processes the requests                             |
| `EmployeeDaoProxy`  | Proxy that decides whether to forward requests (acts as handler link)|

---

## 🔗 How This Code Implements Chain of Responsibility

1. `main()` makes a call to the `EmployeeDaoProxy`.
2. The proxy **checks access permissions**.
3. If allowed (`client == "ADMIN"`), it **forwards the request** to the real DAO (`EmployeeDaoImpl`).
4. If not allowed, it throws an access denied error — effectively **ending the chain**.

---

## 📄 Source Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Data class
class EmployeeDo {
public:
    int employeeId;
    string name;
    string email;
};

// DAO Interface
class EmployeeDao {
public:
    virtual void create(string client, EmployeeDo* obj) throw(exception) = 0;
    virtual void deleteEmployee(string client, int employeeId) throw(exception) = 0;
    virtual EmployeeDo* get(string client, int employeeId) throw(exception) = 0;
};

// Actual Implementation
class EmployeeDaoImpl : public EmployeeDao {
public:
    void create(string client, EmployeeDo* obj) throw(exception) override {
        cout << "✅ Created new row in the Employee table." << endl;
    }

    void deleteEmployee(string client, int employeeId) throw(exception) override {
        cout << "🗑️ Deleted row with employeeId: " << employeeId << endl;
    }

    EmployeeDo* get(string client, int employeeId) throw(exception) override {
        cout << "📂 Fetching data from DB..." << endl;
        return new EmployeeDo();
    }
};

// Proxy/Handler
class EmployeeDaoProxy : public EmployeeDao {
public:
    EmployeeDao* employeeDaoObj;

    EmployeeDaoProxy() {
        employeeDaoObj = new EmployeeDaoImpl();
    }

    void create(string client, EmployeeDo* obj) throw(exception) override {
        if (client == "ADMIN") {
            employeeDaoObj->create(client, obj);
            return;
        }
        throw runtime_error("❌ Access Denied: create");
    }

    void deleteEmployee(string client, int employeeId) throw(exception) override {
        if (client == "ADMIN") {
            employeeDaoObj->deleteEmployee(client, employeeId);
            return;
        }
        throw runtime_error("❌ Access Denied: delete");
    }

    EmployeeDo* get(string client, int employeeId) throw(exception) override {
        if (client == "ADMIN") {
            return employeeDaoObj->get(client, employeeId);
        }
        throw runtime_error("❌ Access Denied: get");
    }
};

// Main Function
int main() {
    try {
        EmployeeDao* empTableObj = new EmployeeDaoProxy();
        empTableObj->create("ADMIN", new EmployeeDo());
        cout << "🎉 Operation successful." << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


@startuml
interface EmployeeDao {
  +create(client, obj)
  +deleteEmployee(client, employeeId)
  +get(client, employeeId)
}

class EmployeeDo

class EmployeeDaoImpl {
  +create(client, obj)
  +deleteEmployee(client, employeeId)
  +get(client, employeeId)
}

class EmployeeDaoProxy {
  -EmployeeDao* employeeDaoObj
  +create(client, obj)
  +deleteEmployee(client, employeeId)
  +get(client, employeeId)
}

EmployeeDao <|-- EmployeeDaoImpl
EmployeeDao <|-- EmployeeDaoProxy
@enduml


main()
 └──> EmployeeDaoProxy::create("ADMIN", obj)
       └──> Check if client == "ADMIN"
             └──> EmployeeDaoImpl::create("ADMIN", obj)

If client is not ADMIN:

main()
 └──> EmployeeDaoProxy::create("GUEST", obj)
       └──> Access Denied ❌


✅ Benefits of Chain of Responsibility
Decouples sender from the handler

Easier to add multiple permission levels (e.g., Manager, HR)

Clean separation of access logic and core logic

🛠️ Compile & Run
bash
Copy
Edit
g++ employee_chain.cpp -o employee_chain
./employee_chain
✨ Summary
We've used Chain of Responsibility to control access via EmployeeDaoProxy.

You can easily add more layers (e.g., logging, validation) by extending the chain.

