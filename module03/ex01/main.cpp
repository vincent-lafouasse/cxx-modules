#include "ScavTrap.hpp"

int main() {
    {
        ScavTrap trap("Poss");

        for (int i = 0; i < 15; i++) {
            trap.attack("zbreh");
            // trap.guard_guate();
        }
    }
}
