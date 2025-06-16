#include <cstdlib>
#include <iostream>

#include "Zombie.hpp"

int main() {
    const int N = 10;

    Zombie* horde;
    try {
        horde = zombieHorde(N, "Garrosh");
    } catch (const std::bad_alloc& e) {
        std::cerr << "Failed to allocated zombie horde\n";
        std::exit(1);
    }

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
}
