#include <cstdlib>
#include <iostream>

#include "Zombie.hpp"

int main() {
    // fuck all this shit, these shouldn't be raw pointers
    Zombie* bob;
    try {
        bob = newZombie("bob");
    } catch (const std::bad_alloc& e) {
        std::cerr << "Failed to allocate zombie Bob\n";
        std::exit(1);
    }
    Zombie* rob;
    try {
        rob = newZombie("bob");
    } catch (const std::bad_alloc& e) {
        std::cerr << "Failed to allocate zombie Rob\n";
        std::exit(1);
    }
    bob->announce();
    rob->announce();
    delete bob;
    delete rob;

    randomChump("allie");
    randomChump("annie");
}
