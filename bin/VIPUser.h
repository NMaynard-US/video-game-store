#ifndef VIPUSER_H
#define VIPUSER_H

#include "User.h"

class VIPUser : public User {
public:
    VIPUser(std::string n, std::string e, std::string a);
    double getDiscount() const override;
};

#endif