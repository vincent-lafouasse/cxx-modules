#pragma once

#include "AMateria.hpp"
#include "Character/ICharacter.hpp"

class Ice : public AMateria {
   public:
    Ice();
    Ice(const Ice& o);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter&);
};
