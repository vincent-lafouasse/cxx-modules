#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm* forestMaker(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* robotomizer(const std::string& target) {
    return new RobotomyRequestFormForm(target);
}

AForm* pardoner(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const std::pair<const char*, Intern::formMaker> Intern::factories[n] = {
    std::make_pair<const char*, formMaker>("create shrubbery", forestMaker),
    std::make_pair<const char*, formMaker>("robotomy request", robotomizer),
    std::make_pair<const char*, formMaker>("presidential pardon", pardoner),
};
