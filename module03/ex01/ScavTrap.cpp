#include "ScavTrap.hpp"

#include <iostream>

namespace {
const bool default_guard_state = false;

const char* named_ctor_msg = "ScavTrap named ctor\n";
const char* he_dead = "ScavTrap cant do shit cause its dead\n";
const char* he_tired = "ScavTrap cant do shit cause its tired\n";

const char* now_guarding = "ScavTrap is now guarding\n";
const char* already_guarding = "ScavTrap is already guarding\n";

const char* default_ctor_msg = "ScavTrap default ctor\n";
const char* copy_ctor_msg = "ScavTrap copy ctor\n";
const char* copy_op_msg = "ScavTrap copy assignment op\n";
const char* dtor_msg = "ScavTrap dtor\n";
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
      isGuarding(default_guard_state) {
    std::cout << default_ctor_msg;
}

ScavTrap::ScavTrap(const ScavTrap& o)
    : ClapTrap(o.name, o.health_points, o.energy_points, o.attack_points),
      isGuarding(default_guard_state) {
    std::cout << copy_ctor_msg;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& o) {
    std::cout << copy_op_msg;
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    this->isGuarding = o.isGuarding;
    return *this;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, base_hp, base_energy, base_attack),
      isGuarding(default_guard_state) {
    std::cout << named_ctor_msg;
}

ScavTrap::~ScavTrap() {
    std::cout << dtor_msg;
}

void ScavTrap::attack(const std::string& target) {
    if (this->health_points == 0) {
        std::cout << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    this->energy_points--;
    std::cout << "ScavTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << " for " << this->attack_points;
    std::cout << " points\n";
}

void ScavTrap::takeDamage(uint32_t amount) {
    if (this->health_points == 0) {
        std::cout << "Stop shooting, ScavTrap is already down\n";
        return;
    }

    uint32_t true_amount =
        amount > this->health_points ? this->health_points : amount;
    this->health_points -= true_amount;
    std::cout << "ScavTrap takes " << true_amount << " dmg\n";
}

void ScavTrap::beRepaired(uint32_t amount) {
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    std::cout << "ScavTrap is healed for " << amount << " hp\n";
    this->energy_points--;
    this->health_points += amount;
}

void ScavTrap::guard_guate() {
    if (this->health_points == 0) {
        std::cout << he_dead;
        return;
    }
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    if (!this->isGuarding) {
        std::cout << now_guarding;
        this->isGuarding = true;
    } else {
        std::cout << already_guarding;
    }
}
