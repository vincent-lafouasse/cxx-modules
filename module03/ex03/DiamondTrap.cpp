#include "DiamondTrap.hpp"

#include <iostream>

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"

#define PURPLE "\033[0;35m"
#define YELLOW "\033[0;33m"

#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#define LOG_FUNCTION_NAME(color) \
    std::clog << color << __PRETTY_FUNCTION__ << RESET << std::endl;

const char* DiamondTrap::default_name = "Drew";
const uint32_t DiamondTrap::base_hp = FragTrap::base_hp;
const uint32_t DiamondTrap::base_energy = ScavTrap::base_energy;
const uint32_t DiamondTrap::base_attack = FragTrap::base_attack;

DiamondTrap::DiamondTrap()
    : ClapTrap(std::string(default_name) + "_clap_name",
               base_hp,
               base_energy,
               base_attack),
      FragTrap(),
      ScavTrap(),
      name(default_name) {
    LOG_FUNCTION_NAME(GREEN);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.ClapTrap::name,
               other.health_points,
               other.energy_points,
               other.attack_points),
      FragTrap(),
      ScavTrap(),
      name(other.name) {
    LOG_FUNCTION_NAME(GREEN);
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name, base_hp, base_energy, base_attack),
      FragTrap(),
      ScavTrap() {
    LOG_FUNCTION_NAME(GREEN);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    (void)other;
    return *this;
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {}
