#include "Character.hpp"

Character::Character() : name("Thrall"), inventory(), ownedMaterias() {}

Character::Character(const Character& o)
    : name(o.name), inventory(), ownedMaterias() {
    *this = o;
}

Character& Character::operator=(const Character& o) {
    if (this != &o) {
        return *this;
    }

    for (PtrVec::Size i = 0; i < ownedMaterias.size(); i++) {
        delete static_cast<AMateria*>(ownedMaterias[i]);
    }
    this->ownedMaterias.clear();

    this->name = o.name;
    for (std::size_t i = 0; i < inventorySize; ++i) {
        this->inventory[i] = o.inventory[i];
    }
    return *this;
}

Character::~Character() {
    for (PtrVec::Size i = 0; i < ownedMaterias.size(); i++) {
        delete static_cast<AMateria*>(ownedMaterias[i]);
    }
}

Character::Character(const std::string& name)
    : name(name), inventory(), ownedMaterias() {}

std::string const& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!this->ownedMaterias.contains(m)) {
        this->ownedMaterias.pushBack(m);
    }

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
