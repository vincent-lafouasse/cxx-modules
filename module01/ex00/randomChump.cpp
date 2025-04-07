#include "Zombie.hpp"

void randomChump(std::string name) {
    const Zombie z(name);
    z.announce();
}
