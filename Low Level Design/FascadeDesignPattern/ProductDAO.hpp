#ifndef PRODUCTDAO_HPP
#define PRODUCTDAO_HPP


#include "Product.hpp"

class ProductDAO{
    public:
        Product* getProduct(int id)
        {
            return new Product();
        }
};


#endif