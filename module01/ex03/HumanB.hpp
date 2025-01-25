#pragma once

#include "Weapon.hpp"

#include <iostream>  // bad

class HumanB {
   public:
    HumanB(const std::string& name) : name(name), weapon(nullptr) {}
    void attack() const {
        std::string w = weapon ? weapon->getType() : "bare hands";
        std::cout << name << " " << w << '\n';
    }
    void setWeapon(const Weapon& w) { weapon = &w; }

   private:
    std::string name;
    const Weapon* weapon;
};
