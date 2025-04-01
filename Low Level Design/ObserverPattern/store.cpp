#include <bits/stdc++.h>
#include "Observable.h"
#include "Observer.h"
using namespace std;

int main()
{
    StocksObservable* iphoneStockObservable = new IPhoneObservableImpl();  // ✅ Ensure this is correct

    NotificationAlertObserver* observer1 = new EmailAlertObserverImpl("abc@gmail.com", iphoneStockObservable);
    NotificationAlertObserver* observer2 = new EmailAlertObserverImpl("xyz@gmail.com", iphoneStockObservable);
    NotificationAlertObserver* observer3 = new MobileAlertObserverImpl("xyz_username", iphoneStockObservable);



    iphoneStockObservable->add(observer1);
    iphoneStockObservable->add(observer2);
    iphoneStockObservable->add(observer3);

    iphoneStockObservable->setStockCount(10);
    iphoneStockObservable->setStockCount(0);
    iphoneStockObservable->setStockCount(100);
}