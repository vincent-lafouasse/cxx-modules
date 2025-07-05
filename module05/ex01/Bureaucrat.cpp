#include "Bureaucrat.hpp"

#include <sstream>

namespace {
std::string toString(Bureaucrat::GradeType grade) {
    std::stringstream ss;

    ss << +grade;

    return ss.str();
}
}  // namespace

// ----- Ctors/Dtors

Bureaucrat::Bureaucrat(const std::string& name, GradeType grade)
    : name(name), grade(grade) {
    Bureaucrat::checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& o) : name(o.name), grade(o.grade) {
    Bureaucrat::checkGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

// ----- Mutators

void Bureaucrat::moveUp() {
    Bureaucrat::checkGrade(grade - 1);
    this->grade--;
}

void Bureaucrat::moveDown() {
    Bureaucrat::checkGrade(grade + 1);
    this->grade++;
}

// ----- Accessors

const std::string& Bureaucrat::getName() const {
    return name;
}

Bureaucrat::GradeType Bureaucrat::getGrade() const {
    return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat " << +b.getGrade() << ".\n";
    return os;
}

void Bureaucrat::checkGrade(GradeType grade) {
    if (grade < Bureaucrat::topGrade) {
        throw GradeTooHighException(grade);
    }

    if (grade > Bureaucrat::bottomGrade) {
        throw GradeTooLowException(grade);
    }
}

// ----- Deleted operations

Bureaucrat::Bureaucrat() : name(), grade() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&) {
    throw std::runtime_error("cannot assign bureaucrats");
}

// ----- Exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeType grade)
    : std::runtime_error("Grade too high: " + toString(grade)) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeType grade)
    : std::runtime_error("Grade too low: " + toString(grade)) {}
