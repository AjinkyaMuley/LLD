# Chain of Responsibility Pattern in C++

## 🧠 Concept: Chain of Responsibility

The **Chain of Responsibility** is a behavioral design pattern that allows an object to send a command **without knowing which object** will handle the request. This pattern creates a **chain of handler objects**, and passes the request along the chain until one of the handlers deals with it.

---

## 🧾 Code Explanation

This project demonstrates the **Chain of Responsibility pattern** using an `EmployeeDaoProxy` which acts as a gatekeeper (proxy) to restrict or allow access to methods of the actual data access object `EmlpoyeeDaoImpl`.

### Classes Overview

| Class | Responsibility |
|-------|----------------|
| `EmployeeDo` | A simple POJO/DTO for employee data. |
| `EmployeeDao` | Abstract base class (interface) defining contract methods. |
| `EmlpoyeeDaoImpl` | Actual implementation of `EmployeeDao`, interacting with DB (simulated via `cout`). |
| `EmployeeDaoProxy` | Controls access and routes request conditionally based on `client` value. |

### 🔗 How Chain of Responsibility is Applied

- The **client** sends requests (`create`, `deleteEmployee`, `get`) to `EmployeeDaoProxy`.
- The **proxy** checks if the `client` is `"ADMIN"`.
- If authorized, it **forwards the request** to the next handler (`EmlpoyeeDaoImpl`).
- Otherwise, it **throws an exception**—effectively **terminating** the request chain.

```cpp
empTableObj->create("ADMIN", new EmployeeDo());
// Proxy checks access and passes to real DAO if permitted
