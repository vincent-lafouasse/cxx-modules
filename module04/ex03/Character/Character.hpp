#pragma once

#include "ICharacter.hpp"
#include "Materia/AMateria.hpp"

class Character : public ICharacter {
   public:
    Character();
    Character(const Character& o);
    Character& operator=(const Character& o);
    ~Character();

    explicit Character(const std::string& name);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);

    void use(int idx, ICharacter& target);

   private:
    std::string name;

    static const std::size_t inventorySize = 4;
    AMateria* inventory[Character::inventorySize];
};
