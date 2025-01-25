#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {
	std::cout << "ripbozo " << name << "\n";
}


void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
