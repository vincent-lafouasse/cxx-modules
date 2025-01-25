#include <fstream>
#include <iostream>
#include <string>

struct Data {
    static Data from_sysargs(int ac, const char* av[]);
    bool is_valid() const;

    std::string file;
    std::string before;
    std::string after;
};

Data Data::from_sysargs(int ac, const char** av) {
    if (ac != 4) {
        std::cout << "Usage: ./cool_sed file before after\n";
        exit(EXIT_FAILURE);
    }

    std::string file(av[1]);
    std::string before = av[2];
    std::string after = av[3];

    std::ifstream read_check(file);
    if (!read_check.good()) {
        std::cout << "File is not readable\n";
        exit(EXIT_FAILURE);
    }
    if (before.empty()) {
        std::cout << "Pattern cannot be empty\n";
        exit(EXIT_FAILURE);
    }

    return (Data){.file = file, .before = before, .after = after};
}
