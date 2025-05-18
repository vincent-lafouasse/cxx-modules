#pragma once

#include <stdint.h>
#include <string>

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(const ClapTrap&);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap&);

    explicit ClapTrap(const std::string& name);
    void attack(const std::string& target);
    void takeDamage(uint32_t amount);
    void beRepaired(uint32_t amount);

   private:
    std::string name;
    uint32_t health_points;
    uint32_t energy_points;
    uint32_t attack_points;

    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
