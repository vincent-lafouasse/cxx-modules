#pragma once

#include "Weapon.hpp"

class HumanB {
   public:
    explicit HumanB(const std::string& name);
    void attack() const;
    void setWeapon(const Weapon& w);

   private:
    std::string name;
    const Weapon* weapon;
};
