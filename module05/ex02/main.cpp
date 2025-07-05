#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

namespace {
void logException(const std::exception& e) {
    std::cout << "Caught exception [" << e.what() << "]";
    std::cout << " from wrecking my stack\n";
}
}  // namespace

int main() {
    {
        ShrubberyCreationForm f("forest");
        std::cout << f;

        Bureaucrat poss("poss", 69);
        std::cout << poss;
        poss.signForm(f);
        f.execute(poss);
    }
    {
        ShrubberyCreationForm f("forest");
        std::cout << f;
        Bureaucrat poss("poss", 150);
        std::cout << poss;
        try {
            poss.signForm(f);
        } catch (const std::exception& e) {
            logException(e);
        }
    }
    {
        ShrubberyCreationForm f("forest");
        std::cout << f;
        Bureaucrat poss("poss", 145);
        std::cout << poss;
        poss.signForm(f);
        try {
            f.execute(poss);
        } catch (const std::exception& e) {
            logException(e);
        }
    }
}
