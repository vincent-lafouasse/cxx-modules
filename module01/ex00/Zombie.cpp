#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) : name(name) {
    std::clog << "-- [Zombie::Zombie(" << name << ")]\n";
}

Zombie::~Zombie() {
    std::clog << "-- [Zombie::~Zombie()]\n";
    std::clog << "-- ripbozo " << name << "\n";
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
