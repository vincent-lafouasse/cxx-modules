#include "ScavTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 20; i++) {
        trap.attack("zbreh");
        trap.beRepaired(4);
        trap.takeDamage(50);
    }
}

int main() {
    {
        ScavTrap trap("Poss");

        trap.guard_guate();
        trap.guard_guate();
        trap.guard_guate();
        routine(trap);
        trap.guard_guate();
        trap.guard_guate();
        trap.guard_guate();
    }
}
