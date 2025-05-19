#pragma once

#include "AMateria.hpp"
#include "Character/ICharacter.hpp"

class Ice : public AMateria {
   public:
    Ice() {}
    Ice(const Ice& other) {}
    Ice& operator=(const Ice& other) { return *this; }
    ~Ice() {}

    AMateria* clone() const { return NULL; }
    void use(ICharacter& target) {}
};
