#ifndef BALANCE_HPP
#define BALANCE_HPP

class Balance{
    public:
        double amountOwe;
        double amountGetBack;

        double getAmountOwe()
        {
            return amountOwe;
        }

        void setAmountOwe(double amount)
        {
            this->amountOwe = amount;
        }

        double getAmountGetBack()
        {
            return amountGetBack;
        }

        void setAmountGetBack(double amount)
        {
            this->amountGetBack = amount;
        }
};


#endif