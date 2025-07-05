#include "AForm.hpp"

#include <sstream>

namespace {
std::string toString(AForm::GradeType grade) {
    std::stringstream ss;

    ss << +grade;

    return ss.str();
}
}  // namespace

// ----- Ctors/Dtors

AForm::AForm(const std::string& name,
             GradeType sigRequirement,
             GradeType execRequirement)
    : name(name),
      isSigned(false),
      signatureRequirement(sigRequirement),
      executionRequirement(execRequirement) {
    AForm::checkGrade(sigRequirement);
    AForm::checkGrade(execRequirement);
}

AForm::AForm(const AForm& o)
    : name(o.name),
      isSigned(o.isSigned),
      signatureRequirement(o.signatureRequirement),
      executionRequirement(o.executionRequirement) {}

AForm::~AForm() {}

void AForm::checkGrade(GradeType grade) {
    if (grade < Grade::topGrade) {
        throw GradeTooHighException(grade);
    }

    if (grade > Grade::bottomGrade) {
        throw GradeTooLowException(grade);
    }
}

// ----- Mutators

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->signatureRequirement) {
        throw AForm::GradeTooLowException(b.getGrade());
    }
    this->isSigned = true;
}

// ----- Accessors

const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getSignatureStatus() const {
    return this->isSigned;
}

AForm::GradeType AForm::getSignatureRequirement() const {
    return this->signatureRequirement;
}

AForm::GradeType AForm::getExecutionRequirement() const {
    return this->executionRequirement;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm " << f.getName() << " {\n";
    os << '\t' << "Required grades:\n";
    os << "\t\t" << "For signature:\t" << +f.getSignatureRequirement() << '\n';
    os << "\t\t" << "For execution:\t" << +f.getExecutionRequirement() << '\n';
    os << '\t' << (f.getSignatureStatus() ? "Signed" : "Not signed") << '\n';
    os << "}\n";

    return os;
}

// ----- Deleted operations

AForm::AForm()
    : name(), isSigned(), signatureRequirement(), executionRequirement() {
    throw std::runtime_error("cannot create form without info");
}

AForm& AForm::operator=(const AForm&) {
    throw std::runtime_error("cannot assign forms");
}

// ----- Exceptions

AForm::GradeTooHighException::GradeTooHighException(GradeType grade)
    : std::runtime_error("Grade too high: " + toString(grade)) {}

AForm::GradeTooLowException::GradeTooLowException(GradeType grade)
    : std::runtime_error("Grade too low: " + toString(grade)) {}
