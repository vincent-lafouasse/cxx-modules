#include "Harl.hpp"

#include <iostream>

namespace {
typedef void (Harl::*complaint)() const;

const char* debug_msg =
    "[DEBUG] I love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-special- ketchup burger. I "
    "really do!\n";

const char* info_msg =
    "[INFO]\nI cannot believe adding extra bacon costs more money. You "
    "didn’t put enough bacon in my burger! If you did, I wouldn’t "
    "be asking for more!\n";

const char* warning_msg =
    "[WARNING]\nI think I deserve to have some extra bacon for "
    "free. I’ve "
    "been coming for years whereas you started working here since "
    "last month.\n";
const char* error_msg =
    "[ERROR]\nThis is unacceptable! I want to speak to the manager "
    "now.\n";
}  // namespace

void Harl::complain(std::string level) {
    static const std::pair<const char*, complaint> complaints[] = {
        std::make_pair("DEBUG", &Harl::debug),
        std::make_pair("INFO", &Harl::info),
        std::make_pair("WARNING", &Harl::warning),
        std::make_pair("ERROR", &Harl::error),
    };
    const size_t sz = sizeof(complaints) / sizeof(*complaints);

    for (size_t i = 0; i < sz; i++) {
        if (complaints[i].first == level) {
            (this->*(complaints[i].second))();
            break;
        }
    }
}

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
