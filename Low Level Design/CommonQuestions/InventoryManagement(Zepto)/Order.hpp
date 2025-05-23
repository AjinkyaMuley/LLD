#ifndef ORDER_HPP
#define ORDER_HPP

#include <unordered_map>
using namespace std;

// Forward declarations
class User;
class Address;
class Warehouse;
class OrderStatus;
class PaymentMode;

// Full includes for types used directly
#include "Invoice.hpp"
#include "Payment.hpp"
#include "UPIPaymentMode.hpp"

class Order {
public:
    User* user;
    Address* deliveryAddress;
    unordered_map<int, int> productCategoryAndCountMap;
    Warehouse* warehouse;
    Invoice* invoice;
    Payment* payment;
    OrderStatus* orderStatus;

    Order(User* user, Warehouse* warehouse) {
        this->user = user;
        this->productCategoryAndCountMap = user->getUserCart()->getCartItems();
        this->warehouse = warehouse;
        this->deliveryAddress = user->address;
        invoice = new Invoice();
        invoice->generateInvoice(this);
    }

    void checkout() {
        warehouse->removeItemFromInventory(productCategoryAndCountMap);

        bool isPaymentSuccess = makePayment(new UPIPaymentMode());

        if (isPaymentSuccess) {
            user->getUserCart()->emptyCart();
        } else {
            warehouse->addItemToInventory(productCategoryAndCountMap);
        }
    }

    bool makePayment(PaymentMode* paymentMode) {
        payment = new Payment(paymentMode);
        return payment->makePayment();
    }

    void generateOrderInvoice() {
        invoice->generateInvoice(this);
    }
};

#endif
