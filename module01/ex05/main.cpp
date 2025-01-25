#include "Harl.hpp"

#include <iostream>

int main() {
    Harl harl;

    while (1) {
        std::string level;
        if (std::cin.eof())
            break;
        std::cout << "> ";
        std::cin >> level;
        if (level.empty())
            continue;

        harl.complain(level);
    }
}
