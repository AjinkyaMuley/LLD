### `Observable.h`

- **`StocksObservable` Class:** An abstract class that defines the interface for adding, removing, and notifying observers. It also includes methods to set and get the stock count.

  ```cpp
  class StocksObservable {
  public:
      virtual void add(NotificationAlertObserver *observer) = 0;
      virtual void remove(NotificationAlertObserver *observer) = 0;
      virtual void notifySubscribers() = 0;
      virtual void setStockCount(int newStockCount) = 0;
      virtual int getStockCount() = 0;
  };
  ```

- **`IPhoneObservableImpl` Class:** A concrete implementation of `StocksObservable`. It maintains a list of observers and the stock count. It notifies observers when the stock count changes from 0 to a positive number.

  ```cpp
  class IPhoneObservableImpl : public StocksObservable {
  public:
      list<NotificationAlertObserver *> observerList;
      int stockCount = 0;

      void add(NotificationAlertObserver *observer) override {
          observerList.push_back(observer);
      }
      void remove(NotificationAlertObserver *observer) override {
          observerList.remove(observer);
      }
      void notifySubscribers() override {
          for (auto observer : observerList) {
              observer->update();
          }
      }
      void setStockCount(int newStockCount) override {
          bool wasOutOfStock = (stockCount == 0);
          stockCount += newStockCount;

          if (wasOutOfStock && stockCount > 0) {
              notifySubscribers();
          }
      }
      int getStockCount() override {
          return stockCount;
      }
  };
  ```

### `Observer.h`

- **`NotificationAlertObserver` Class:** An abstract class that defines the `update` method, which is called when the subject's state changes.

  ```cpp
  class NotificationAlertObserver {
  public:
      virtual void update() = 0;
  };
  ```

- **`EmailAlertObserverImpl` Class:** A concrete implementation of `NotificationAlertObserver`. It sends an email notification when the stock is available.

  ```cpp
  class EmailAlertObserverImpl : public NotificationAlertObserver {
      string emailId;
      StocksObservable *observable;

      void sendMail(string emailId, string message) {
          cout << "mail sent to :" << emailId << endl;
      }

  public:
      EmailAlertObserverImpl(string emailId, StocksObservable *observable) {
          this->emailId = emailId;
          this->observable = observable;
      }

      void update() override {
          sendMail(emailId, "product is in stock hurry up!");
      }
  };
  ```

- **`MobileAlertObserverImpl` Class:** Another concrete implementation of `NotificationAlertObserver`. It sends a mobile message notification when the stock is available.

  ```cpp
  class MobileAlertObserverImpl : public NotificationAlertObserver {
      string userName;
      StocksObservable *observable;

      void sendMsg(string userName, string message) {
          cout << "msg sent to :" << userName << endl;
      }

  public:
      MobileAlertObserverImpl(string userName, StocksObservable *observable) {
          this->userName = userName;
          this->observable = observable;
      }

      void update() override {
          sendMsg(userName, "product is in stock hurry up!");
      }
  };
  ```

### `store.cpp`

- The `main` function demonstrates the creation of an `IPhoneObservableImpl` object and several observers (`EmailAlertObserverImpl` and `MobileAlertObserverImpl`). It adds these observers to the observable and changes the stock count to trigger notifications.

  ```cpp
  int main() {
      StocksObservable* iphoneStockObservable = new IPhoneObservableImpl();

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
  ```
