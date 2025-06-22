#ifndef REGULARUSER_H
#define REGULARUSER_H

#include "User.h"

class RegularUser : public User {
public:
    RegularUser(std::string n, std::string e, std::string a);
    double getDiscount() const override;
};

#endif