#include "ScavTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 15; i++) {
        trap.attack("zbreh");
        trap.takeDamage(3);
        trap.beRepaired(4);
    }
}

int main() {
    {
        ScavTrap trap("Poss");

        trap.guard_guate();
        trap.guard_guate();
        trap.guard_guate();
        routine(trap);
    }
}
