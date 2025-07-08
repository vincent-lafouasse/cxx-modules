#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace {
void logException(const std::exception& e) {
    std::cout << "Caught exception [" << e.what() << "]";
    std::cout << " from wrecking my stack\n";
}
}  // namespace

int main() {
    std::srand(std::time(0));
    {
        ShrubberyCreationForm f("forest");
        std::cout << f;

        Bureaucrat poss("poss", 69);
        std::cout << poss;
        poss.signForm(f);
        f.execute(poss);
        std::cout << std::endl;
    }
    {
        ShrubberyCreationForm f("forest");
        std::cout << f;
        Bureaucrat poss("poss", 69);
        std::cout << poss;
        try {
            f.execute(poss);
        } catch (const std::exception& e) {
            logException(e);
        }
        std::cout << std::endl;
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
        std::cout << std::endl;
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
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        RobotomyRequestFormForm f("no thoughts");
        Bureaucrat poss("poss", 1);
        poss.signForm(f);
        f.execute(poss);
        std::cout << std::endl;
    }

    {
        const AForm::GradeType grade = 26;
        Bureaucrat b("poss", grade);
        PresidentialPardonForm f("form");

        try {
            b.signForm(f);
        } catch (const std::exception& e) {
            logException(e);
        }
        std::cout << std::endl;
    }
    {
        const AForm::GradeType grade = 6;
        Bureaucrat b("poss", grade);
        PresidentialPardonForm f("form");
        b.signForm(f);

        try {
            f.execute(b);
        } catch (const std::exception& e) {
            logException(e);
        }
        std::cout << std::endl;
    }
    {
        const AForm::GradeType grade = 5;
        Bureaucrat b("poss", grade);
        PresidentialPardonForm f("form");
        b.signForm(f);
        f.execute(b);
        std::cout << std::endl;
    }
}
