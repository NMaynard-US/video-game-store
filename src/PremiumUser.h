#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

class PremiumUser : public User {
public:
    PremiumUser(std::string n, std::string e, std::string a);
    double getDiscount() const override;
};

#endif