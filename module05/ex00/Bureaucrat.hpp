#pragma once

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include <string>

typedef uint8_t u8;

class Bureaucrat {
   public:
    Bureaucrat(const std::string& name, u8 grade);

    Bureaucrat(const Bureaucrat&);
    Bureaucrat& operator=(const Bureaucrat&);
    ~Bureaucrat();

    const std::string& getName() const;
    u8 getGrade() const;

    class GradeTooHighException : public std::runtime_error {
       public:
        GradeTooHighException(u8 grade)
            : std::runtime_error("Grade too high"), grade(grade) {}

        u8 grade;
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        GradeTooLowException(u8 grade)
            : std::runtime_error("Grade too low"), grade(grade) {}

        u8 grade;
    };

   private:
    Bureaucrat();

    const std::string name;
    uint8_t grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
