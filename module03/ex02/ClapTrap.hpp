#pragma once

#include <stdint.h>
#include <string>

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
    ClapTrap(const std::string& name,
             uint32_t health_points,
             uint32_t energy_points,
             uint32_t attack_points);
    std::string name;
    uint32_t health_points;
    uint32_t energy_points;
    uint32_t attack_points;
};
