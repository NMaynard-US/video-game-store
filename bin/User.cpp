#include "User.h"
#include <iostream>
#include <iomanip>

User::User(std::string n, std::string e, std::string a)
    : name(n), email(e), address(a) {}

void User::addToCart(Product* product, int quantity) {
    cart.addProduct(product, quantity);
}

void User::viewCart() {
    cart.viewCart();
}

void User::checkout(std::map<std::string, Product*>& catalog, std::mutex& catalogMutex) {
    std::cout << name << ", your total is $" << std::fixed << std::setprecision(2)
              << cart.calculateTotal(getDiscount()) << " after discount." << std::endl;
    std::cout << "Confirm purchase? (yes/no): ";
    std::string input;
    std::cin >> input;

    if (input == "yes") {
        std::lock_guard<std::mutex> lock(catalogMutex);
        for (const auto& item : cart.getItems()) {
            Product* p = item.second.first;
            int quantity = item.second.second;
            if (p->getStock() >= quantity) {
                p->updateStock(-quantity);
            } else {
                std::cout << "Not enough stock for: " << p->getName() << std::endl;
            }
        }
        std::cout << "Purchase completed!\\n";
        cart.clearCart();
    } else {
        std::cout << "Purchase canceled.\\n";
    }
}