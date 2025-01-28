#include "ClapTrap.hpp"

#include <iostream>

namespace {
const char* default_ctor_msg = "ClapTrap default ctor\n";
const char* copy_ctor_msg = "ClapTrap copy ctor\n";
const char* copy_op_msg = "ClapTrap copy assignment op\n";
const char* dtor_msg = "ClapTrap dtor\n";

const char* named_ctor_msg = "ClapTrap named ctor\n";
const char* he_dead = "ClapTrap cant do shit cause its dead\n";
const char* he_tired = "ClapTrap cant do shit cause its tired\n";
}  // namespace

ClapTrap::ClapTrap()
    : name(""), health_points(0), energy_points(0), attack_points(0) {
    std::cout << default_ctor_msg;
}

ClapTrap::ClapTrap(const ClapTrap& o)
    : name(o.name),
      health_points(o.health_points),
      energy_points(o.energy_points),
      attack_points(o.attack_points) {
    std::cout << copy_ctor_msg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& o) {
    std::cout << copy_op_msg;
    this->name = o.name;
    this->health_points = o.health_points;
    this->energy_points = o.energy_points;
    this->attack_points = o.attack_points;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << dtor_msg;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), health_points(10), energy_points(10), attack_points(0) {
    std::cout << named_ctor_msg;
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

    std::cout << "ClapTrap " << this->name;
    std::cout << " attacks " << target;
    std::cout << " for " << this->attack_points;
    std::cout << " points\n";
}

void ClapTrap::takeDamage(uint32_t amount) {}

void ClapTrap::beRepaired(uint32_t amount) {}
