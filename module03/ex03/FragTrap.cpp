#include "FragTrap.hpp"

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

namespace {
const char* he_dead = "FragTrap cant do shit cause its dead\n";
const char* he_tired = "FragTrap cant do shit cause its tired\n";

const char* request_high_five = "Eyyyy give me a high five\n";
}  // namespace

const char* FragTrap::default_name = "Frankie";
const uint32_t FragTrap::base_hp = 100;
const uint32_t FragTrap::base_energy = 100;
const uint32_t FragTrap::base_attack = 30;

FragTrap::FragTrap()
    : ClapTrap(default_name, base_hp, base_energy, base_attack) {
    LOG_FUNCTION_NAME(GREEN);
}

FragTrap::FragTrap(const FragTrap& o)
    : ClapTrap(o.name, o.health_points, o.energy_points, o.attack_points) {
    LOG_FUNCTION_NAME(GREEN);
    *this = o;
}

FragTrap& FragTrap::operator=(const FragTrap& o) {
    LOG_FUNCTION_NAME(BLUE);
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    return *this;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name, base_hp, base_energy, base_attack) {
    LOG_FUNCTION_NAME(GREEN);
}

FragTrap::~FragTrap() {
    LOG_FUNCTION_NAME(RED);
}

void FragTrap::attack(const std::string& target) {
    if (this->health_points == 0) {
        std::cout << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    this->energy_points--;
    std::cout << "FragTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << " for " << this->attack_points;
    std::cout << " points\n";
}

void FragTrap::highFivesGuys() const {
    if (this->health_points == 0) {
        std::cout << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    std::cout << request_high_five;
}
