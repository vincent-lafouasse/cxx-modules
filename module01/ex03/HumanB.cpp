#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::attack() const {
    std::string w = this->weapon ? this->weapon->getType() : "bare hands";
    std::cout << name << " attacks with their " << w << '\n';
}

void HumanB::setWeapon(const Weapon& w) {
    this->weapon = &w;
}
