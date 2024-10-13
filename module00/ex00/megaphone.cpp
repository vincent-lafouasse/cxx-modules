#include <cctype>
#include <iostream>
#include <string>

typedef std::string::const_iterator const_str_it;

void yell(const std::string &in) {
  for (const_str_it it = in.cbegin(); it != in.cend(); it++) {
    std::cout << static_cast<char>(std::toupper(*it));
  }
}

int main(int ac, char *av[]) {
  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return EXIT_SUCCESS;
  }
  for (int i = 1; i < ac; i++) {
    yell(av[i]);
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
