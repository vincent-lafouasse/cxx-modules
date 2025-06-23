#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap();
    FragTrap(const FragTrap&);
    FragTrap& operator=(const FragTrap&);
    ~FragTrap();

    explicit FragTrap(const std::string& name);
    void attack(const std::string& target) /* override */;
    void highFivesGuys() const;

   private:
    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
