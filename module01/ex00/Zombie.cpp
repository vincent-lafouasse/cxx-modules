#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) : name(name) {}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
