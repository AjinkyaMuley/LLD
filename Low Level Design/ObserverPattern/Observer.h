#pragma once
#include <bits/stdc++.h>
using namespace std;

// Forward declaration of StocksObservable
class StocksObservable;

class NotificationAlertObserver
{
public:
    virtual void update() = 0;
};

class EmailAlertObserverImpl : public NotificationAlertObserver
{
    string emailId;
    StocksObservable *observable;  // ✅ Now StocksObservable is recognized

    void sendMail(string emailId, string message)
    {
        cout << "mail sent to :" << emailId << endl;
    }

public:
    EmailAlertObserverImpl(string emailId, StocksObservable *observable)  // ✅ Correct constructor
    {
        this->emailId = emailId;
        this->observable = observable;
    }

    void update() override
    {
        sendMail(emailId, "product is in stock hurry up!");
    }
};

class MobileAlertObserverImpl : public NotificationAlertObserver
{
    string userName;
    StocksObservable *observable;  // ✅ Now StocksObservable is recognized

    void sendMsg(string userName, string message)
    {
        cout << "msg sent to :" << userName << endl;
    }

public:
    MobileAlertObserverImpl(string userName, StocksObservable *observable)  // ✅ Correct constructor
    {
        this->userName = userName;
        this->observable = observable;
    }

    void update() override
    {
        sendMsg(userName, "product is in stock hurry up!");
    }
};
