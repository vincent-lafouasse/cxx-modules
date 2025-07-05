#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

namespace {
void logException(const std::exception& e) {
    std::cout << "Caught exception [" << e.what() << "]";
    std::cout << " from wrecking my stack\n";
}
}  // namespace

int main() {
    ShrubberyCreationForm f("forest");

    Bureaucrat poss("poss", 69);
    poss.signForm(f);
    f.execute(poss);
}
