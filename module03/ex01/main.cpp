#include "ScavTrap.hpp"

int main() {
    {
        ScavTrap trap;

        for (int i = 0; i < 15; i++) {
            trap.attack("zbreh");
        }
    }
}
