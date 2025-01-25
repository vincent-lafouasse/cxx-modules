#include "Zombie.hpp"

int main() {
    const int N = 10;

    Zombie* horde = zombieHorde(N, "Garrosh");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
}
