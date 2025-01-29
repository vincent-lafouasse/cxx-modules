#include "Zombie.hpp"

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
