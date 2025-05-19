#include "ClapTrap.hpp"

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
const char* he_dead = "ClapTrap cant do shit cause its dead\n";
const char* he_tired = "ClapTrap cant do shit cause its tired\n";
}  // namespace

const char* ClapTrap::default_name = "Camille";
const uint32_t ClapTrap::base_hp = 10;
const uint32_t ClapTrap::base_energy = 10;
const uint32_t ClapTrap::base_attack = 0;

ClapTrap::ClapTrap()
    : name(default_name),
      health_points(base_hp),
      energy_points(base_energy),
      attack_points(base_attack) {
    LOG_FUNCTION_NAME(GREEN);
}

ClapTrap::ClapTrap(const ClapTrap& o)
    : name(o.name),
      health_points(o.health_points),
      energy_points(o.energy_points),
      attack_points(o.attack_points) {
    LOG_FUNCTION_NAME(GREEN);
}

ClapTrap::ClapTrap(const std::string& name,
                   uint32_t health_points,
                   uint32_t energy_points,
                   uint32_t attack_points)
    : name(name),
      health_points(health_points),
      energy_points(energy_points),
      attack_points(attack_points) {
    LOG_FUNCTION_NAME(PURPLE);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& o) {
    LOG_FUNCTION_NAME(BLUE);
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    return *this;
}

ClapTrap::~ClapTrap() {
    LOG_FUNCTION_NAME(RED);
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name),
      health_points(base_hp),
      energy_points(base_energy),
      attack_points(base_attack) {
    LOG_FUNCTION_NAME(GREEN);
}

void ClapTrap::attack(const std::string& target) {
    if (this->health_points == 0) {
        std::cout << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    this->energy_points--;
    std::cout << "ClapTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << " for " << this->attack_points;
    std::cout << " points\n";
}

void ClapTrap::takeDamage(uint32_t amount) {
    if (this->health_points == 0) {
        std::cout << "Stop shooting, ClapTrap is already down\n";
        return;
    }

    uint32_t true_amount =
        amount > this->health_points ? this->health_points : amount;
    this->health_points -= true_amount;
    std::cout << "ClapTrap takes " << true_amount << " dmg\n";
}

void ClapTrap::beRepaired(uint32_t amount) {
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    std::cout << "ClapTrap is healed for " << amount << " hp\n";
    this->energy_points--;
    this->health_points += amount;
}
