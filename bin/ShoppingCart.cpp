#include "ShoppingCart.h"
#include <iostream>

void ShoppingCart::addProduct(Product* product, int quantity) {
    items[product->getName()] = { product, quantity };
}

void ShoppingCart::viewCart() const {
    std::cout << "\\nShopping Cart:\\n";
    for (const auto& item : items) {
        std::cout << item.first << " x" << item.second.second << "\\n";
    }
}

double ShoppingCart::calculateTotal(double discount) const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.second.first->getPrice() * item.second.second;
    }
    return total * (1 - discount);
}

const std::map<std::string, std::pair<Product*, int>>& ShoppingCart::getItems() const {
    return items;
}