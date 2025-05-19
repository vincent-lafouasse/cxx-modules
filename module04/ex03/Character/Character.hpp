#pragma once

#include "ICharacter.hpp"
#include "Materia/AMateria.hpp"

class Character : public ICharacter {
   public:
    Character() {}
    Character(const Character& o) {}
    Character& operator=(const Character& o) { return *this; }
    ~Character() {}

    std::string const& getName() const { return this->name; }
    void equip(AMateria* m) {}
    void unequip(int idx) {}
    void use(int idx, ICharacter& target) {}

   private:
    std::string name;
};
