#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <map>
#include <string>
#include "Product.h"

class ShoppingCart {
private:
    std::map<std::string, std::pair<Product*, int>> items;

public:
    void addProduct(Product* product, int quantity);
    void viewCart() const;
    double calculateTotal(double discount) const;
    const std::map<std::string, std::pair<Product*, int>>& getItems() const;
    void clearCart();
};

#endif