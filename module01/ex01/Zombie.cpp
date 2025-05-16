#include "Zombie.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << std::endl;

Zombie::Zombie() {
    LOG_FUNCTION();
}

Zombie::~Zombie() {
    LOG_FUNCTION();
}

void Zombie::set_name(const std::string& name) {
    this->name = name;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
