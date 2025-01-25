#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie* bob = newZombie("bob");
    Zombie* rob = newZombie("rob");
    bob->announce();
    rob->announce();
    delete bob;
    delete rob;

    randomChump("allie");
    randomChump("annie");
}
