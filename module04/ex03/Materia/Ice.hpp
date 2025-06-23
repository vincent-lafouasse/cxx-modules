#pragma once

#include "AMateria.hpp"
#include "Character/ICharacter.hpp"

#include <iostream>  // bad

class Ice : public AMateria {
   public:
    Ice() : AMateria("ice") {}
    Ice(const Ice& o) : AMateria(o.type) {}
    Ice& operator=(const Ice& other) {
        this->type = other.type;
        return *this;
    }
    ~Ice() {}

    AMateria* clone() const { return new Ice(*this); }

    void use(ICharacter&) {
        std::cout << "* heals " << "DUMMY" << "'s wounds *";
    }
};
