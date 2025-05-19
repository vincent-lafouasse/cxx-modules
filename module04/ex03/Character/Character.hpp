#pragma once

#include "ICharacter.hpp"
#include "Materia/AMateria.hpp"

class Character : public ICharacter {
   public:
    Character() {}
    Character(const Character& o) {}
    Character& operator=(const Character& o) { return *this; }
    ~Character() {}

    explicit Character(const std::string& name) : name(name) {}

    std::string const& getName() const { return this->name; }
    void equip(AMateria* m) {
        for (std::size_t i = 0; i < Character::inventorySize; ++i) {
            if (inventory[i] == NULL) {
                inventory[i] = m;
                return;
            }
        }
    }

    void unequip(int idx) { inventory[idx] = NULL; }

    void use(int idx, ICharacter& target) {
        if (inventory[idx]) {
            inventory[idx]->use(target);
        }
    }

   private:
    std::string name;
    AMateria* inventory[4];

    static const std::size_t inventorySize = 4;
};
