#pragma once

#include <string>
#include <stdint.h>

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(const ClapTrap&);
    virtual ~ClapTrap();
    ClapTrap& operator=(const ClapTrap&);

    explicit ClapTrap(const std::string& name);
    virtual void attack(const std::string& target);
    virtual void takeDamage(uint32_t amount);
    virtual void beRepaired(uint32_t amount);

   protected:
    std::string name;
    uint32_t health_points;
    uint32_t energy_points;
    uint32_t attack_points;
};
