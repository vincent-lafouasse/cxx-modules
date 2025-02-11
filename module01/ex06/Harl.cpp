#include "Harl.hpp"

#include <iostream>

namespace {
const char* debug_msg =
    "[DEBUG]\nI love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-special- ketchup burger. I "
    "really do!\n\n";

const char* info_msg =
    "[INFO]\nI cannot believe adding extra bacon costs more money. You "
    "didn’t put enough bacon in my burger! If you did, I wouldn’t "
    "be asking for more!\n\n";

const char* warning_msg =
    "[WARNING]\nI think I deserve to have some extra bacon for "
    "free. I’ve "
    "been coming for years whereas you started working here since "
    "last month.\n\n";
const char* error_msg =
    "[ERROR]\nThis is unacceptable! I want to speak to the manager "
    "now.\n\n";
const char* chill_msg =
    "[chill]\nsomebody once told me the world is gonna roll me\n\n";
}  // namespace

void Harl::debug() const {
    std::cout << debug_msg;
}

void Harl::info() const {
    std::cout << info_msg;
}

void Harl::warning() const {
    std::cout << warning_msg;
}

void Harl::error() const {
    std::cout << error_msg;
}

void Harl::ramble() const {
    std::cout << chill_msg;
}
