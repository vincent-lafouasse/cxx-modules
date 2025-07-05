#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
   public:
    typedef Bureaucrat::GradeType GradeType;

    Form(const std::string& name,
         GradeType sigRequirement,
         GradeType execRequirement);

    Form(const Form&);
    ~Form();

    void beSigned(const Bureaucrat&);

    class GradeTooHighException : public std::runtime_error {
       public:
        explicit GradeTooHighException(GradeType grade);
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        explicit GradeTooLowException(GradeType grade);
    };

   private:
    Form();
    Form& operator=(const Form&);

    void checkGrade(GradeType grade);

    const std::string name;
    bool isSigned;
    const GradeType signatureRequirement;
    const GradeType executionRequirement;
};

std::ostream& operator<<(std::ostream&, const Form&);
