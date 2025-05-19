#include "DiamondTrap.hpp"

void routine(ClapTrap& trap) {
    for (int i = 0; i < 10; i++) {
        trap.attack("zbreh");
        trap.takeDamage(5);
        trap.beRepaired(4);
    }
}

int main() {
    {
        DiamondTrap trap("Poss");

        trap.highFivesGuys();
        routine(trap);
        trap.whoAmI();
        trap.highFivesGuys();
    }
}
