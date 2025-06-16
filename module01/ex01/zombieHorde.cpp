#include "Zombie.hpp"

#include <new>

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie* zombies = new (std::nothrow) Zombie[N];
    if (zombies == NULL) {
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        zombies[i].set_name(name);
    }

    return zombies;
}
