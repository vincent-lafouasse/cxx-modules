#pragma once

#include "Weapon.hpp"

class HumanA {
   public:
    void attack() const;

   private:
    Weapon& weapon;
    std::string name;
};
