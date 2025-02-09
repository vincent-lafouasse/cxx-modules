#pragma once

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(const std::string& name, const Weapon& weapon);
    void attack() const;

   private:
    std::string name;
    const Weapon& weapon;
};
