#include "Product.h"
#include <iostream>

Product::Product(std::string n, std::string d, double p, int s)
    : name(n), description(d), price(p), stock(s) {}

void Product::updateStock(int change) { stock += change; }
void Product::updatePrice(double newPrice) { price = newPrice; }

void Product::showProduct() const {
    std::cout << name << " - " << description << ", $" << price << ", Stock: " << stock << "\n";
}

std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }