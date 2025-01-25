#include <fstream>
#include <iostream>
#include <string>

struct Config {
    static Config from_sysargs(int ac, char* av[]);
    void log() const;

    std::string file;
    std::string before;
    std::string after;
};

Config Config::from_sysargs(int ac, char** av) {
    if (ac != 4) {
        std::cout << "Usage: ./cool_sed file before after\n";
        exit(EXIT_FAILURE);
    }

    std::string file(av[1]);
    std::string before = av[2];
    std::string after = av[3];

    std::ifstream read_check(file);
    if (read_check.fail()) {
        std::cout << "File is not readable\n";
        exit(EXIT_FAILURE);
    }
    if (before.empty()) {
        std::cout << "Pattern cannot be empty\n";
        exit(EXIT_FAILURE);
    }

    return (Config){.file = file, .before = before, .after = after};
}

void Config::log() const {
    std::cout << "file\t" << file << '\n';
    std::cout << "before\t" << before << '\n';
    std::cout << "after\t" << after << '\n';
}

int main(int ac, char* av[]) {
    Config cfg = Config::from_sysargs(ac, av);
    cfg.log();
}
