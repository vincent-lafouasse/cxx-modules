#include "Harl.hpp"

#include <iostream>

void Harl::debug() const {
    std::cout << " love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special- ketchup burger. I "
                 "really do!\n";
}

void Harl::info() const {
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!\n";
}

void Harl::warning() const {
    std::cout << " think I deserve to have some extra bacon for free. I’ve "
                 "been coming for years whereas you started working here since "
                 "last month.\n";
}

void Harl::error() const {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
