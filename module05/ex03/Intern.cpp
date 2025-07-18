#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

AForm* Intern::makeForm(const std::string& name,
                        const std::string& target) const {
    for (std::size_t i = 0; i < Intern::n; ++i) {
        const std::string& formName = Intern::factories[i].first;
        const formMaker maker = Intern::factories[i].second;

        if (name == formName) {
            AForm* out = maker(target);
            std::cout << "Intern creates " << out->getName() << std::endl;
            return out;
        }
    }

    std::cout << "Intern couldnt find form " << name << std::endl;
    return NULL;
}

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {}
