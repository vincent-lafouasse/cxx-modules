#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : name(""), health_points(0), energy_points(0), attack_points(0) {}

ClapTrap::ClapTrap(const ClapTrap& o)
    : name(o.name),
      health_points(o.health_points),
      energy_points(o.energy_points),
      attack_points(o.attack_points) {}

ClapTrap& ClapTrap::operator=(const ClapTrap& o) {
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    return *this;
}

ClapTrap::~ClapTrap() {}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), health_points(10), energy_points(10), attack_points(0) {}

void ClapTrap::attack(const std::string& target) {}

void ClapTrap::takeDamage(uint32_t amount) {}

void ClapTrap::beRepaired(uint32_t amount) {}
