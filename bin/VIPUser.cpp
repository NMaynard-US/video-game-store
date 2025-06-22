#include "VIPUser.h"

VIPUser::VIPUser(std::string n, std::string e, std::string a)
    : User(n, e, a) {}

double VIPUser::getDiscount() const {
    return 0.20; // 20% discount
}