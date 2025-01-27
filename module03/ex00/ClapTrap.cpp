#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name(name), health_points(10), energy_points(10), attack_points(0) {}

void ClapTrap::attack(const std::string& target) {}

void ClapTrap::takeDamage(uint32_t amount) {}

void ClapTrap::beRepaired(uint32_t amount) {}
