#include "Config.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

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
        std::exit(EXIT_FAILURE);
    }
    if (before.empty()) {
        std::cout << "Pattern cannot be empty\n";
        std::exit(EXIT_FAILURE);
    }

    std::string out_path = file + ".replace";
    std::ofstream out(out_path.c_str());
    if (out.fail()) {
        std::cout << "Failed to open " << out_path << " for writing\n";
        std::exit(EXIT_FAILURE);
    }

    return Config(file, before, after);
}

Config::Config(const std::string& file,
               const std::string& before,
               const std::string& after)
    : file(file), before(before), after(after) {}

void Config::log() const {
    std::cout << "file\t" << file << '\n';
    std::cout << "before\t" << before << '\n';
    std::cout << "after\t" << after << '\n';
}
