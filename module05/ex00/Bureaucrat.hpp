#pragma once

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include <string>

typedef uint8_t u8;

class Bureaucrat {
   public:
    typedef u8 GradeType;

    Bureaucrat(const std::string& name, GradeType grade);

    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat() /* = default */;

    const std::string& getName() const;
    GradeType getGrade() const;

    class GradeTooHighException : public std::runtime_error {
       public:
        GradeTooHighException(GradeType grade);

        GradeType grade;
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        GradeTooLowException(GradeType grade);

        GradeType grade;
    };

   private:
    Bureaucrat() /* = delete */;
    Bureaucrat& operator=(const Bureaucrat&) /* = delete */;

    static void checkGrade(GradeType grade);  // throws if grade is invalid
    static const GradeType topGrade = 1;
    static const GradeType bottomGrade = 150;

    const std::string name;
    GradeType grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
