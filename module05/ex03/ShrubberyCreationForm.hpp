#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    typedef Grade::Type GradeType;

    explicit ShrubberyCreationForm(const std::string& target);

    ShrubberyCreationForm(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();

    void executeUnchecked(const Bureaucrat&) const /* override */;

   private:
    ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

    static const GradeType sigRequirement = 145;
    static const GradeType execRequirement = 137;

    const std::string target;
};
