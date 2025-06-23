#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    ScavTrap();
    ScavTrap(const ScavTrap&);
    ScavTrap& operator=(const ScavTrap&);
    ~ScavTrap();

    explicit ScavTrap(const std::string& name);
    void attack(const std::string& target) /* override */;
    void guard_gate();

   private:
    bool isGuarding;

    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
