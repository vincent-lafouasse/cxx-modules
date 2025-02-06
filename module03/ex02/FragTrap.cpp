#include "FragTrap.hpp"

#include <iostream>

namespace {
const char* default_name = "Finley";
const uint32_t base_hp = 100;
const uint32_t base_energy = 100;
const uint32_t base_attack = 30;

const char* named_ctor_msg = "FragTrap named ctor\n";
const char* he_dead = "FragTrap cant do shit cause its dead\n";
const char* he_tired = "FragTrap cant do shit cause its tired\n";

const char* request_high_five = "Eyyyy give me a high five\n";

const char* default_ctor_msg = "FragTrap default ctor\n";
const char* copy_ctor_msg = "FragTrap copy ctor\n";
const char* copy_op_msg = "FragTrap copy assignment op\n";
const char* dtor_msg = "FragTrap dtor\n";
}  // namespace

FragTrap::FragTrap()
    : ClapTrap(default_name, base_hp, base_energy, base_attack) {
    std::cout << default_ctor_msg;
}

FragTrap::FragTrap(const FragTrap& o)
    : ClapTrap(o.name, o.health_points, o.energy_points, o.attack_points) {
    std::cout << copy_ctor_msg;
    *this = o;
}

FragTrap& FragTrap::operator=(const FragTrap& o) {
    std::cout << copy_op_msg;
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    return *this;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name, base_hp, base_energy, base_attack) {
    std::cout << named_ctor_msg;
}

FragTrap::~FragTrap() {
    std::cout << dtor_msg;
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

void FragTrap::takeDamage(uint32_t amount) {
    if (this->health_points == 0) {
        std::cout << "Stop shooting, FragTrap is already down\n";
        return;
    }

    uint32_t true_amount =
        amount > this->health_points ? this->health_points : amount;
    this->health_points -= true_amount;
    std::cout << "FragTrap takes " << true_amount << " dmg\n";
}

void FragTrap::beRepaired(uint32_t amount) {
    if (this->energy_points == 0) {
        std::cout << he_tired;
        return;
    }

    std::cout << "FragTrap is healed for " << amount << " hp\n";
    this->energy_points--;
    this->health_points += amount;
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
