#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() : inventory() {}

MateriaSource::MateriaSource(const MateriaSource& other) : inventory() {
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this == &other) {
        return *this;
    }

    this->clearInventory();
    for (std::size_t i = 0; i < inventorySize; i++) {
        if (other.inventory[i] != NULL) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    this->clearInventory();
}

void MateriaSource::clearInventory() {
    for (std::size_t i = 0; i < inventorySize; i++) {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (std::size_t i = 0; i < inventorySize; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (std::size_t i = 0; i < inventorySize; i++) {
        const AMateria* current = inventory[i];
        if (current->getType() == type) {
            return current->clone();
        }
    }
    return NULL;
}
