#pragma once

#include <cstdint>
#include <string>

class ClapTrap {
   public:
    ClapTrap(const std::string& name);

    void attack(const std::string& target);
    void takeDamage(uint32_t amount);
    void beRepaired(uint32_t amount);

   private:
    std::string name;
    uint32_t health_points;
    uint32_t energy_points;
    uint32_t attack_points;
};
