#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {
    std::clog << "-- [Zombie::Zombie()]\n";
}

Zombie::~Zombie() {
    std::clog << "-- [Zombie::~Zombie()]\n";
    std::clog << "-- ripbozo " << name << "\n";
}

void Zombie::set_name(const std::string& name) {
    this->name = name;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
