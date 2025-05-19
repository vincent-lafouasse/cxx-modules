#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
   DiamondTrap();
   DiamondTrap(const DiamondTrap& other);
   DiamondTrap& operator=(const DiamondTrap& other);
   ~DiamondTrap();
   explicit DiamondTrap(const std::string& name);

   void attack(const std::string& target);
   void whoAmI();

private:
   std::string name;

    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
