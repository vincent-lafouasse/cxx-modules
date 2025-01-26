#include "Config.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

static std::string load_entire_file(const std::string& path);
static bool matches_pattern(const std::string& pattern,
                            const std::string& data,
                            std::size_t offset);

int main(int ac, char* av[]) {
    Config cfg = Config::from_sysargs(ac, av);
    cfg.log();

    const std::string data = load_entire_file(cfg.file);
    std::cout << data;

    const std::string path = cfg.file + ".replace";
    std::ofstream out(path.c_str());

    for (std::size_t i = 0; i < data.size();) {
        if (matches_pattern(cfg.before, data, i)) {
            out << cfg.after;
            i += cfg.before.size();
        } else {
            out << data[i];
            i++;
        }
    }
}

static bool matches_pattern(const std::string& pattern,
                            const std::string& data,
                            std::size_t offset) {
    return data.compare(offset, pattern.size(), pattern) == 0;
}

static std::string load_entire_file(const std::string& path) {
    std::ifstream file(path.c_str());
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
