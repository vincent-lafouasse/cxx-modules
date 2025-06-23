#include "ScavTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 20; i++) {
        trap.attack("zbreh");
        trap.beRepaired(4);
        trap.takeDamage(50);
    }
}

void checkVirtualDtor() {
    ClapTrap* t = new ScavTrap();
    t->attack("magus");
    t->beRepaired(420);
    delete t;
}

int main() {
    {
        ScavTrap trap("Poss");

        trap.guard_gate();
        trap.guard_gate();
        trap.guard_gate();
        routine(trap);
        trap.guard_gate();
        trap.guard_gate();
        trap.guard_gate();
    }

    checkVirtualDtor();
}
