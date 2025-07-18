#include "Bureaucrat.hpp"

#include <sstream>

#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << '\n';
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << f.getName();
        std::cout << " because " << e.what() << '\n';
    }
}

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
    if (grade < Grade::topGrade) {
        throw GradeTooHighException(grade);
    }

    if (grade > Grade::bottomGrade) {
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
