#include "Config.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>

Config Config::from_sysargs(int ac, char** av) {
    if (ac != 4) {
        std::cout << "Usage: ./cool_sed file before after\n";
        exit(EXIT_FAILURE);
    }

    std::string file(av[1]);
    std::string before(av[2]);
    std::string after(av[3]);

    std::ifstream read_check(file.c_str());
    if (read_check.fail()) {
        std::cout << "File is not readable\n";
        exit(EXIT_FAILURE);
    }
    if (before.empty()) {
        std::cout << "Pattern cannot be empty\n";
        exit(EXIT_FAILURE);
    }

    std::string out_path = file + ".replace";
    std::ofstream out(out_path.c_str());
    if (out.fail()) {
        std::cout << "Failed to open " << out_path << " for writing\n";
        exit(EXIT_FAILURE);
    }

    return (Config){.file = file, .before = before, .after = after};
}

void Config::log() const {
    std::cout << "file\t" << file << '\n';
    std::cout << "before\t" << before << '\n';
    std::cout << "after\t" << after << '\n';
}
