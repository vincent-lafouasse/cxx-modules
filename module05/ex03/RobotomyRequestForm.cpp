#include "RobotomyRequestForm.hpp"

#include <cstdlib>

#include "AForm.hpp"

namespace {
const char* formName = "RobotomyRequestFormForm";
}  // namespace

RobotomyRequestFormForm::RobotomyRequestFormForm(const std::string& target)
    : AForm(formName, sigRequirement, execRequirement), target(target) {}

RobotomyRequestFormForm::RobotomyRequestFormForm(
    const RobotomyRequestFormForm& o)
    : AForm(o), target(o.target) {}

RobotomyRequestFormForm::~RobotomyRequestFormForm() {}

void RobotomyRequestFormForm::executeUnchecked(const Bureaucrat& b) const
/* override */ {
    int rn = std::rand() % 2;

    if (rn == 0) {
        std::cout << ":))))) --- " << b.getName()
                  << " doesnt have a brain anymore\n";
    } else {
        std::cout << ":((((( --- " << b.getName()
                  << " still has a brain, sadge\n";
    }
}

RobotomyRequestFormForm::RobotomyRequestFormForm() : AForm() {
    throw std::runtime_error("cannot create form without a target");
}

RobotomyRequestFormForm& RobotomyRequestFormForm::operator=(
    const RobotomyRequestFormForm&) {
    throw std::runtime_error("cannot assign forms");
}
