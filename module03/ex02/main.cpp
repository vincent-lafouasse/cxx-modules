#include "FragTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 10; i++) {
        trap.attack("zbreh");
        trap.takeDamage(40);
        trap.beRepaired(4);
    }
}

ClapTrap* fromUser() {
    return new FragTrap();
}

int main() {
    {
        FragTrap trap("Poss");

        trap.highFivesGuys();
        trap.highFivesGuys();
        trap.highFivesGuys();
        routine(trap);
        trap.highFivesGuys();
        trap.highFivesGuys();
        trap.highFivesGuys();
    }
    {
        ClapTrap* trap = fromUser();
        routine(*trap);
        delete trap;
    }
}
