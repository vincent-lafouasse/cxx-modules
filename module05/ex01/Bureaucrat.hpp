#pragma once

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include <string>

typedef uint8_t u8;

namespace Grade {
typedef u8 Type;

static const Type topGrade = 1;
static const Type bottomGrade = 150;
}  // namespace Grade

class Bureaucrat {
   public:
    typedef Grade::Type GradeType;

    Bureaucrat(const std::string& name, GradeType grade);

    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat() /* = default */;

    const std::string& getName() const;
    GradeType getGrade() const;

    void moveUp();
    void moveDown();

    class GradeTooHighException : public std::runtime_error {
       public:
        explicit GradeTooHighException(GradeType grade);
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        explicit GradeTooLowException(GradeType grade);
    };

   private:
    Bureaucrat() /* = delete */;
    Bureaucrat& operator=(const Bureaucrat&) /* = delete */;

    static void checkGrade(GradeType grade);  // throws if grade is invalid

    const std::string name;
    GradeType grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
