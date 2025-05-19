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
