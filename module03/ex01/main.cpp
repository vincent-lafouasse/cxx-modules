#include "ClapTrap.hpp"

int main() {
    {
        ClapTrap trap;

        for (int i = 0; i < 15; i++) {
            trap.attack("zbreh");
        }
    }
    {
        ClapTrap trap("Bobby");

        for (int i = 0; i < 15; i++) {
            trap.beRepaired(100);
        }
    }
}
