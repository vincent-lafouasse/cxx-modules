#pragma once

#include "AMateria.hpp"
#include "Character/ICharacter.hpp"

class Cure : public AMateria {
   public:
    Cure();
    Cure(const Cure& o);
    Cure& operator=(const Cure& other);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter&);
};
