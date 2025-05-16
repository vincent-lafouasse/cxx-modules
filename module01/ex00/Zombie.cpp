#include "Zombie.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << std::endl;

Zombie::Zombie(const std::string& name) : name(name) {
    LOG_FUNCTION();
}

Zombie::~Zombie() {
    LOG_FUNCTION();
    std::clog << "-- ripbozo " << name << "\n";
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
