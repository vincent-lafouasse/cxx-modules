#include "Harl.hpp"

#include <iostream>

typedef void (Harl::*complaint)(void) const;

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
    std::cout << "I love having extra bacon for my "
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
