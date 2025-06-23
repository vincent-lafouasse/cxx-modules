#include "Character.hpp"

Character::Character() : name("Thrall"), inventory() {}

Character::Character(const Character& o) {}

Character& Character::operator=(const Character& o) {
    return *this;
}

Character::~Character() {}

Character::Character(const std::string& name) : name(name), inventory() {}

std::string const& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    for (std::size_t i = 0; i < Character::inventorySize; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (inventory[idx]) {
        inventory[idx]->use(target);
    }
}
