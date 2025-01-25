#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : name("") {}

Zombie::~Zombie() {
    std::cout << "ripbozo " << name << "\n";
}

void Zombie::set_name(const std::string& name) {
    this->name = name;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
