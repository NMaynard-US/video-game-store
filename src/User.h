#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <mutex>
#include "ShoppingCart.h"
#include "Product.h"

class User {
protected:
    std::string name, email, address;
    ShoppingCart cart;

public:
    User(std::string n, std::string e, std::string a);
    virtual double getDiscount() const = 0;

    void addToCart(Product* product, int quantity);
    void viewCart();
    void checkout(std::map<std::string, Product*>& catalog, std::mutex& catalogMutex);
};

#endif