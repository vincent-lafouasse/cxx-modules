#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

namespace {
void yell(const std::string& s);
const char* no_args_message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}  // namespace

int main(int ac, char* av[]) {
    if (ac == 1) {
        std::cout << no_args_message << std::endl;
        return EXIT_SUCCESS;
    }

    for (int i = 1; i < ac; i++) {
        yell(av[i]);
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

namespace {
void yell(const std::string& s) {
    // i should be using s.cbegin() and s.cend() here, fuck C++98
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << static_cast<char>(std::toupper(*it));
    }
}
}  // namespace
