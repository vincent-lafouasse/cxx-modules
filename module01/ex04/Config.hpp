#pragma once

#include <string>

struct Config {
    Config(const std::string& file,
           const std::string& before,
           const std::string& after);
    static Config from_sysargs(int ac, char* av[]);
    void log() const;

    std::string file;
    std::string before;
    std::string after;
};
