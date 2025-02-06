#include <cstdlib>
#include <iostream>
#include "Harl.hpp"

#define USAGE "Usage: harlFilter level"

enum Level { Debug, Info, Warning, Error, None };

Level parse(const std::string& level) {
    if (level == "DEBUG")
        return Debug;
    if (level == "INFO")
        return Info;
    if (level == "WARNING")
        return Warning;
    if (level == "ERROR")
        return Error;
    return None;
}

int main(int ac, char** av) {
    if (ac != 2) {
        std::cout << USAGE << std::endl;
        std::exit(EXIT_FAILURE);
    }

    Harl harl;
    Level level = parse(av[1]);

    switch (level) {
        case Debug:
            harl.debug();
        case Info:
            harl.info();
        case Warning:
            harl.warning();
        case Error:
            harl.error();
        case None:
            harl.ramble();
    }
}
