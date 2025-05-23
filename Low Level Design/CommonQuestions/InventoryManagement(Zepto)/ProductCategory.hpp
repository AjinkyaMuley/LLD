#ifndef PRODUCTCATEGORY_HPP
#define PRODUCTCATEGORY_HPP


#include <bits/stdc++.h>
using namespace std;

class Product;

class ProductCategory{
    public:
        int productCategoryId;
        string categoryName;
        vector<Product*> products = vector<Product*>();
        double price;

        void addProduct(Product* product)
        {
            products.push_back(product);
        }

        void removeProduct(int count)
        {
            for(int i=0;i<count && !products.empty();i++)
            {
                products.erase(products.begin());
            }
        }
};


#endif