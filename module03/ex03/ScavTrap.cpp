#include "ScavTrap.hpp"

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
const char* he_dead = " cant do shit cause its dead\n";
const char* he_tired = " cant do shit cause its tired\n";
const char* now_guarding = " is now guarding\n";
const char* already_guarding = " is already guarding\n";
}  // namespace

const char* ScavTrap::default_name = "Sam";
const uint32_t ScavTrap::base_hp = 100;
const uint32_t ScavTrap::base_energy = 50;
const uint32_t ScavTrap::base_attack = 20;

ScavTrap::ScavTrap()
    : ClapTrap(ScavTrap::default_name,
               ScavTrap::base_hp,
               ScavTrap::base_energy,
               ScavTrap::base_attack),
      isGuarding(false) {
    LOG_FUNCTION_NAME(GREEN);
}

ScavTrap::ScavTrap(const ScavTrap& o)
    : ClapTrap(o.name, o.health_points, o.energy_points, o.attack_points),
      isGuarding(false) {
    LOG_FUNCTION_NAME(GREEN);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& o) {
    LOG_FUNCTION_NAME(BLUE);
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    this->isGuarding = o.isGuarding;
    return *this;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, base_hp, base_energy, base_attack), isGuarding(false) {
    LOG_FUNCTION_NAME(GREEN);
}

ScavTrap::~ScavTrap() {
    LOG_FUNCTION_NAME(RED);
}

void ScavTrap::attack(const std::string& target) {
    if (this->health_points == 0) {
        std::cout << name << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << name << he_tired;
        return;
    }

    this->energy_points--;
    std::cout << "ScavTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << " for " << this->attack_points;
    std::cout << " points\n";
}

void ScavTrap::guard_gate() {
    if (this->health_points == 0) {
        std::cout << name << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << name << he_tired;
        return;
    }

    if (!this->isGuarding) {
        std::cout << name << now_guarding;
        this->isGuarding = true;
    } else {
        std::cout << name << already_guarding;
    }
}
