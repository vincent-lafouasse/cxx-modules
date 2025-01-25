#include "Config.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool matches_pattern();

std::string load_entire_file(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int ac, char* av[]) {
    Config cfg = Config::from_sysargs(ac, av);
    cfg.log();

    const std::string data = load_entire_file(cfg.file);
    std::cout << data;
}
