# Observer Design Pattern

## Introduction
The **Observer Design Pattern** is a behavioral design pattern that establishes a **one-to-many dependency** between objects. When the **subject (observable)** changes state, all its **observers** are notified and updated automatically. This pattern promotes **loose coupling**, making the system more maintainable and scalable.

## Use Case
In this example, we are implementing a **Stock Notification System** where multiple users (observers) subscribe to stock availability updates. Whenever the stock becomes available, all subscribed users receive a notification via **email** or **mobile message**.

## Components of Observer Pattern
The Observer Pattern consists of the following components:

1. **Subject (Observable)**
   - Maintains a list of observers.
   - Provides methods to **attach, detach**, and **notify** observers.
   - When its state changes, it notifies all attached observers.

2. **Observer**
   - Defines an interface with an `update()` method.
   - Objects that subscribe to the subject must implement this interface.

3. **Concrete Subject (StocksObservable)**
   - Implements the `Observable` interface.
   - Stores the list of observers and manages stock updates.

4. **Concrete Observers (EmailAlertObserverImpl, MobileAlertObserverImpl)**
   - Implements the `Observer` interface.
   - Defines how each observer reacts when notified.

---

## Code Breakdown

### 1. Observer Interface (`NotificationAlertObserver`)
```cpp
class NotificationAlertObserver {
public:
    virtual void update() = 0; // Pure virtual function
};
```
- This interface declares the `update()` method that every observer must implement.

### 2. Concrete Observers (`EmailAlertObserverImpl` & `MobileAlertObserverImpl`)
```cpp
class EmailAlertObserverImpl : public NotificationAlertObserver {
    string emailId;
    StocksObservable *observable;

    void sendMail(string emailId, string message) {
        cout << "Mail sent to: " << emailId << endl;
    }

public:
    EmailAlertObserverImpl(string emailId, StocksObservable *observable) {
        this->emailId = emailId;
        this->observable = observable;
    }

    void update() override {
        sendMail(emailId, "Product is back in stock!");
    }
};
```
```cpp
class MobileAlertObserverImpl : public NotificationAlertObserver {
    string userName;
    StocksObservable *observable;

    void sendMsg(string userName, string message) {
        cout << "Message sent to: " << userName << endl;
    }

public:
    MobileAlertObserverImpl(string userName, StocksObservable *observable) {
        this->userName = userName;
        this->observable = observable;
    }

    void update() override {
        sendMsg(userName, "Product is back in stock!");
    }
};
```
- These classes implement the `update()` method, which defines how they receive notifications.
- `sendMail()` and `sendMsg()` simulate sending notifications via email and mobile messages.

### 3. Observable Interface (`StocksObservable`)
```cpp
class StocksObservable {
public:
    virtual void addObserver(NotificationAlertObserver *observer) = 0;
    virtual void removeObserver(NotificationAlertObserver *observer) = 0;
    virtual void notifyObservers() = 0;
};
```
- Defines methods for adding, removing, and notifying observers.

### 4. Concrete Observable (`IPhoneObservableImpl`)
```cpp
class IPhoneObservableImpl : public StocksObservable {
    vector<NotificationAlertObserver *> observers;
    int stockCount = 0;

public:
    void addObserver(NotificationAlertObserver *observer) override {
        observers.push_back(observer);
    }

    void removeObserver(NotificationAlertObserver *observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update();
        }
    }

    void setStockCount(int count) {
        stockCount = count;
        if (stockCount > 0) {
            notifyObservers();
        }
    }
};
```
- This class maintains a list of observers and manages stock availability.
- When stock is available, it **notifies all observers**.

### 5. Main Function (`store.cpp`)
```cpp
int main() {
    StocksObservable* iphoneStockObservable = new IPhoneObservableImpl();

    NotificationAlertObserver* observer1 = new EmailAlertObserverImpl("abc@gmail.com", iphoneStockObservable);
    NotificationAlertObserver* observer2 = new EmailAlertObserverImpl("xyz@gmail.com", iphoneStockObservable);
    NotificationAlertObserver* observer3 = new MobileAlertObserverImpl("xyz_username", iphoneStockObservable);

    iphoneStockObservable->addObserver(observer1);
    iphoneStockObservable->addObserver(observer2);
    iphoneStockObservable->addObserver(observer3);

    // Simulating stock update
    cout << "Stock added! Notifying observers..." << endl;
    iphoneStockObservable->setStockCount(10);
    
    return 0;
}
```
- We create an `IPhoneObservableImpl` object (`iphoneStockObservable`).
- We create **observers** and attach them to the observable.
- When `setStockCount(10)` is called, all observers are notified.

---

## Sequence Diagram
```plaintext
+-------------+      addObserver()      +------------------+
|  Observer1  | <-------------------- |  StocksObservable |
+-------------+                        +------------------+
+-------------+      addObserver()      +------------------+
|  Observer2  | <-------------------- |  StocksObservable |
+-------------+                        +------------------+

Stock updated -> notifyObservers() -> Observers get updated
```

## Advantages of Observer Pattern
✅ **Decoupling:** Observers and subjects are loosely coupled, making the system more modular.  
✅ **Scalability:** New observers can be added easily without modifying existing code.  
✅ **Better Code Maintainability:** Follows **Open/Closed Principle** (OCP), making the code extensible.

## Real-World Applications
- **Event Listeners in UI frameworks (React, Angular, JavaFX).**
- **Stock market monitoring systems.**
- **Social media notifications (YouTube, Instagram, Twitter).**
- **Messaging applications (WhatsApp, Slack, Discord).**

## Summary
The **Observer Pattern** allows an object (**subject**) to notify multiple dependent objects (**observers**) when its state changes. It is widely used in software engineering for implementing event-driven programming, notification systems, and real-time updates.

---

## References
- [Design Patterns: Elements of Reusable Object-Oriented Software - Gamma et al.](https://en.wikipedia.org/wiki/Design_Patterns)
- [Observer Pattern - Refactoring Guru](https://refactoring.guru/design-patterns/observer)
