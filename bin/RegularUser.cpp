#include "RegularUser.h"

RegularUser::RegularUser(std::string n, std::string e, std::string a)
    : User(n, e, a) {}

double RegularUser::getDiscount() const {
    return 0.0;
}
