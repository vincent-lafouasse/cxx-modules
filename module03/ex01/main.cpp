#include "ScavTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 15; i++) {
        trap.attack("zbreh");
        // trap.guard_guate();
    }
}

int main() {
    {
        ScavTrap trap("Poss");

        routine(trap);
    }
}
