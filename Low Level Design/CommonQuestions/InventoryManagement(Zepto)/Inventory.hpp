#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "ProductCategory.hpp"
#include "Product.hpp"

#include<bits/stdc++.h>
using namespace std;
    
class Inventory{
    public:
        vector<ProductCategory*> productCategoryList;

        Inventory()
        {
            productCategoryList = vector<ProductCategory*>();
        }

        void addCategory(int categoryId,string name,int price)
        {
            ProductCategory* productCategory = new ProductCategory();
            productCategory->price = price;
            productCategory->categoryName = name;
            productCategory->productCategoryId = categoryId;
            productCategoryList.push_back(productCategory);
        }

        void addProduct(Product* product,int productCategoryId)
        {
            ProductCategory* categoryObject = NULL;
            for(auto category : productCategoryList)
            {
                if(category->productCategoryId == productCategoryId)
                {
                    categoryObject = category;
                    break;
                }
            }

            if(categoryObject != NULL)
            {
                categoryObject->addProduct(product);
            }
        }

        void removeItems(unordered_map<int,int> productCategoryAndCountMap)
        {
            for(auto e : productCategoryAndCountMap)
            {
                ProductCategory* category = getProductCategoryFromID(e.first);
                category->removeProduct(e.second);
            }
        }

        private:
            ProductCategory* getProductCategoryFromID(int productCategoryId)
            {
                for(auto category : productCategoryList)
                {
                    if(category->productCategoryId == productCategoryId)
                    {
                        return category;
                    }
                }

                return NULL;
            }
};
    
#endif