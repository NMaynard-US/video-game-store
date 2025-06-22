#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name, description;
    double price;
    int stock;

public:
    Product(std::string n, std::string d, double p, int s);
    void updateStock(int change);
    void updatePrice(double newPrice);
    void showProduct() const;

    std::string getName() const;
    double getPrice() const;
    int getStock() const;
};

#endif
