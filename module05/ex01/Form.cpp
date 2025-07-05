#include "Form.hpp"

#include <sstream>

namespace {
std::string toString(Form::GradeType grade) {
    std::stringstream ss;

    ss << +grade;

    return ss.str();
}
}  // namespace

// ----- Ctors/Dtors

Form::Form(const std::string& name,
     GradeType sigRequirement,
     GradeType execRequirement);

Form::Form(const Form& o) : name(o.name), grade(o.grade) {
    Form::checkGrade(grade);
}

Form::~Form() {}


void Form::checkGrade(GradeType grade) {
    if (grade < Form::topGrade) {
        throw GradeTooHighException(grade);
    }

    if (grade > Form::bottomGrade) {
        throw GradeTooLowException(grade);
    }
}

// ----- Deleted operations

Form::Form(): name(), isSigned(), signatureRequirement(), executionRequirement() {
    throw std::runtime_error("cannot create form without info");
}

Form& Form::operator=(const Form&) {
    throw std::runtime_error("cannot assign forms");
}

// ----- Exceptions

Form::GradeTooHighException::GradeTooHighException(GradeType grade)
    : std::runtime_error("Grade too high: " + toString(grade)) {}

Form::GradeTooLowException::GradeTooLowException(GradeType grade)
    : std::runtime_error("Grade too low: " + toString(grade)) {}
