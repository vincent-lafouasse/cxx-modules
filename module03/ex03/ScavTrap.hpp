#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
   public:
    ScavTrap();
    ScavTrap(const ScavTrap&);
    ScavTrap& operator=(const ScavTrap&);
    ~ScavTrap();

    explicit ScavTrap(const std::string& name);
    void attack(const std::string& target);
    void guard_guate();

   private:
    bool isGuarding;

   protected:
    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
