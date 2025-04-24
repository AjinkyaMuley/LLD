#ifndef PAYMENTFLOW_HPP
#define PAYMENTFLOW_HPP


class PaymentFlow{
    public:
        virtual void validateRequest() = 0;
        virtual void calculateFees() = 0;
        virtual void debitAmount() = 0;
        virtual void creditAmount() = 0;

        virtual void sendMoney() final
        {
            validateRequest();
            calculateFees();
            debitAmount();
            creditAmount();
        }
};


#endif