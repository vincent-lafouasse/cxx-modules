#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    typedef Grade::Type GradeType;

    explicit PresidentialPardonForm(const std::string& target);

    PresidentialPardonForm(const PresidentialPardonForm&);
    ~PresidentialPardonForm();

    void executeUnchecked(const Bureaucrat&) const /* override */;

   private:
    PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);

    static const GradeType sigRequirement = 25;
    static const GradeType execRequirement = 5;

    const std::string target;
};
