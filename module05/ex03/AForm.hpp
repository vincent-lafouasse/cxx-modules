#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
   public:
    typedef Grade::Type GradeType;

    AForm(const std::string& name,
          GradeType sigRequirement,
          GradeType execRequirement);

    AForm(const AForm&);
    virtual ~AForm();

    void execute(const Bureaucrat&) const;

    const std::string& getName() const;
    bool getSignatureStatus() const;
    GradeType getSignatureRequirement() const;
    GradeType getExecutionRequirement() const;

    void beSigned(const Bureaucrat&);

    class GradeTooHighException : public std::runtime_error {
       public:
        explicit GradeTooHighException(GradeType grade);
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        explicit GradeTooLowException(GradeType grade);
    };

    class UnverifiedFormException : public std::runtime_error {
       public:
        explicit UnverifiedFormException();
    };

   protected:
    AForm();
    virtual void executeUnchecked(const Bureaucrat&) const = 0;

   private:
    AForm& operator=(const AForm&);

    static void checkGrade(GradeType grade);

    const std::string name;
    bool isSigned;
    const GradeType signatureRequirement;
    const GradeType executionRequirement;
};

std::ostream& operator<<(std::ostream&, const AForm&);
