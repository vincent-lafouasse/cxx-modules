#include "Config.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

namespace {
[[noreturn]] void die(const char* msg, int status = 1) {
    std::clog << msg << std::endl;
    std::exit(status);
}

[[noreturn]] void die(const std::string& msg, int status = 1) {
    die(msg.c_str(), status);
}
}  // namespace

Config Config::from_sysargs(int ac, char** av) {
    if (ac != 4) {
        die("Usage: ./cool_sed file before after");
    }

    std::string file(av[1]);
    std::string before(av[2]);
    std::string after(av[3]);

    std::ifstream read_check(file.c_str());
    if (read_check.fail()) {
        die("File is not readable");
    }
    if (before.empty()) {
        die("Pattern cannot be empty");
    }

    std::string out_path = file + ".replace";
    std::ofstream out(out_path.c_str());
    if (out.fail()) {
        die("Failed to open " + out_path + " for writing");
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
