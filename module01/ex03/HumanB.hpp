#pragma once

#include "Weapon.hpp"

class HumanB {
   public:
    void attack() const;

   private:
    Weapon* weapon;
    std::string name;
};
