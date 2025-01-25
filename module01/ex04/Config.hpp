#pragma once

#include <string>

struct Config {
    static Config from_sysargs(int ac, char* av[]);
    void log() const;

    std::string file;
    std::string before;
    std::string after;
};
