#pragma once

#include "Weapon.hpp"

#include <iostream>  // bad

class HumanA {
   public:
    HumanA(const std::string& name, const Weapon& weapon)
        : name(name), weapon(weapon) {}
    void attack() const {
        std::cout << name << " " << weapon.getType() << '\n';
    }

   private:
    std::string name;
    const Weapon& weapon;
};
