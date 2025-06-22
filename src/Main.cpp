#include <iostream>
#include <thread>
#include <map>
#include <mutex>

// Include your custom class headers
#include "Product.h"
#include "ShoppingCart.h"
#include "User.h"
#include "RegularUser.h"
#include "PremiumUser.h"
#include "VIPUser.h"

// Function to simulate user checkout
void simulateUser(User* user, std::map<std::string, Product*>& catalog, std::mutex& catalogMutex) {
    user->viewCart();
    user->checkout(catalog, catalogMutex);
}

int main() {
    // Mutex to protect shared product catalog
    std::mutex catalogMutex;

    // Set up product catalog
    std::map<std::string, Product*> catalog;
    catalog["Elden Ring"] = new Product("Elden Ring", "Open-world RPG", 59.99, 10);
    catalog["Halo Infinite"] = new Product("Halo Infinite", "Sci-fi Shooter", 49.99, 5);
    catalog["God of War"] = new Product("God of War", "Action Adventure", 69.99, 8);

    // Create users
    RegularUser user1("Alex", "alex@example.com", "111 Gamer St");
    PremiumUser user2("Brittany", "britt@example.com", "222 Arcade Ave");
    VIPUser user3("Carlos", "carlos@example.com", "333 Pro Blvd");

    // Add products to user carts
    user1.addToCart(catalog["Elden Ring"], 1);
    user2.addToCart(catalog["Halo Infinite"], 2);
    user3.addToCart(catalog["God of War"], 1);
    user3.addToCart(catalog["Elden Ring"], 1);

    // Simulate users checking out in parallel
    std::thread t1(simulateUser, &user1, std::ref(catalog), std::ref(catalogMutex));
    std::thread t2(simulateUser, &user2, std::ref(catalog), std::ref(catalogMutex));
    std::thread t3(simulateUser, &user3, std::ref(catalog), std::ref(catalogMutex));

    // Wait for all users to finish
    t1.join();
    t2.join();
    t3.join();

    // Show remaining inventory
    std::cout << "\nRemaining Inventory:\n";
    for (const auto& pair : catalog) {
        pair.second->showProduct();
    }

    // Clean up memory
    for (auto& pair : catalog) {
        delete pair.second;
    }

    return 0;
}
