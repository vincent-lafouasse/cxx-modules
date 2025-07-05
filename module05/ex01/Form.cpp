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
           GradeType execRequirement)
    : name(name),
      isSigned(false),
      signatureRequirement(sigRequirement),
      executionRequirement(execRequirement) {
    Form::checkGrade(sigRequirement);
    Form::checkGrade(execRequirement);
}

Form::Form(const Form& o)
    : name(o.name),
      isSigned(o.isSigned),
      signatureRequirement(o.signatureRequirement),
      executionRequirement(o.executionRequirement) {}

Form::~Form() {}

void Form::checkGrade(GradeType grade) {
    if (grade < Grade::topGrade) {
        throw GradeTooHighException(grade);
    }

    if (grade > Grade::bottomGrade) {
        throw GradeTooLowException(grade);
    }
}

// ----- Accessors

const std::string& Form::getName() const {
    return this->name;
}

bool Form::getSignatureStatus() const {
    return this->isSigned;
}

Form::GradeType Form::getSignatureRequirement() const {
    return this->signatureRequirement;
}

Form::GradeType Form::getExecutionRequirement() const {
    return this->executionRequirement;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() << " {\n";
    os << '\t'<< "Required grades:\n";
    os << "\t\t" << "For signature:\t" << +f.getSignatureRequirement() << '\n';
    os << "\t\t" << "For execution:\t" << +f.getExecutionRequirement() << '\n';
    os << '\t' << (f.getSignatureStatus() ? "Signed" : "Not signed") << '\n';
    os << "}\n";

    return os;
}

// ----- Deleted operations

Form::Form()
    : name(), isSigned(), signatureRequirement(), executionRequirement() {
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
