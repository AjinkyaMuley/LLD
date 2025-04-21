#ifndef ORDERFACADE_HPP
#define ORDERFACADE_HPP

#include "ProductDAO.hpp"
#include "Invoice.hpp"
#include "Payment.hpp"
#include "SendNotification.hpp"

class OrderFacade{
    public:
        ProductDAO* productDAO;
        Invoice* invoice;
        Payment* payment;
        SendNotification* notification;


        OrderFacade()
        {
            productDAO = new ProductDAO();
            invoice = new Invoice();
            payment = new Payment();
            notification = new SendNotification();
        }

        void createOrder()
        {
            Product* product = productDAO->getProduct(121);
            payment->makePayment();
            invoice->generateInvoice();
            notification->sendNotification();
        }
};


#endif