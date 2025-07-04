#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, u8 grade)
    : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& o) : name(o.name), grade(o.grade) {}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

u8 Bureaucrat::getGrade() const {
    return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat " << b.getGrade() << ".";
    return os;
}

Bureaucrat::Bureaucrat() : name(), grade() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&) {
    throw std::runtime_error("cannot assign bureaucrats");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(u8 grade)
    : std::runtime_error("Grade too high"), grade(grade) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(u8 grade)
    : std::runtime_error("Grade too low"), grade(grade) {}
