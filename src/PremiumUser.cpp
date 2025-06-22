#include "PremiumUser.h"

PremiumUser::PremiumUser(std::string n, std::string e, std::string a)
    : User(n, e, a) {}

double PremiumUser::getDiscount() const {
    return 0.10; // 10% discount
}