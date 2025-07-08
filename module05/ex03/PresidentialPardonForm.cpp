#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

namespace {
const char* formName = "PresidentialPardonForm";
}  // namespace

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(formName, sigRequirement, execRequirement), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
    : AForm(o), target(o.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeUnchecked(const Bureaucrat& b) const
/* override */ {
    std::cout << b.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
    throw std::runtime_error("cannot create form without a target");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm&) {
    throw std::runtime_error("cannot assign forms");
}
