#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie* zombies;
    try {
        zombies = new Zombie[N];
    } catch (const std::bad_alloc& e) {
        throw;
    }

    for (int i = 0; i < N; i++) {
        zombies[i].set_name(name);
    }

    return zombies;
}
