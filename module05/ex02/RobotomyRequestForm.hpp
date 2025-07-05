#pragma once

#include "AForm.hpp"

class RobotomyRequestFormForm : public AForm {
   public:
    typedef Grade::Type GradeType;

    explicit RobotomyRequestFormForm(const std::string& target);

    RobotomyRequestFormForm(const RobotomyRequestFormForm&);
    ~RobotomyRequestFormForm();

    void executeUnchecked(const Bureaucrat&) const /* override */;

   private:
    RobotomyRequestFormForm();
    RobotomyRequestFormForm& operator=(const RobotomyRequestFormForm&);

    static const GradeType sigRequirement = 145;
    static const GradeType execRequirement = 137;

    const std::string target;
};
