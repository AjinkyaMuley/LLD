#ifndef INVOICE_HPP
#define INVOICE_HPP

class Order;  // Forward declaration

class Invoice {
public:
    int totalItemPrice;
    int totalTax;
    int totalFinalPrice;

    void generateInvoice(Order* order)
    {
        totalItemPrice = 200;
        totalTax = 20;
        totalFinalPrice = 220;
    }
};

#endif
