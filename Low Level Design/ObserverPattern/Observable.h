#pragma once
#include <bits/stdc++.h>
#include "Observer.h"
using namespace std;

class StocksObservable
{
public:
    virtual void add(NotificationAlertObserver *observer) = 0;
    virtual void remove(NotificationAlertObserver *observer) = 0;
    virtual void notifySubscribers() = 0;
    virtual void setStockCount(int newStockCount) = 0;
    virtual int getStockCount() = 0;
};

class IPhoneObservableImpl : public StocksObservable
{
public:
    list<NotificationAlertObserver *> observerList;
    int stockCount = 0;

    void add(NotificationAlertObserver *observer) override
    {
        observerList.push_back(observer);
    }
    void remove(NotificationAlertObserver *observer) override
    {
        observerList.remove(observer);
    }
    void notifySubscribers() override
    {
        for (auto observer : observerList)
        {
            observer->update();
        }
    }
    void setStockCount(int newStockCount) override
    {
        bool wasOutOfStock = (stockCount == 0); //  Check if stock was 0 before updating
        stockCount += newStockCount;            // First update the stock count

        if (wasOutOfStock && stockCount > 0) //  Notify only if stock was 0 before
        {
            notifySubscribers();
        }
    }

    int getStockCount() override
    {
        return stockCount;
    }
};
