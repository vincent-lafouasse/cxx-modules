#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "AForm.hpp"

namespace {
const char* formName = "ShrubberyCreationForm";

const char* tree =
    "            ,@@@@@@@,\n"
    "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
    ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
    "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
    "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
    "`&%\\ ` /%&'    |.|        \\ '|8'\n"
    "    |o|        | |         | |\n"
    "    |.|        | |         | |\n"
    " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
}  // namespace

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(formName, sigRequirement, execRequirement), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
    : AForm(o), target(o.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat&) const /* override */ {
    std::string path = this->target + "_shrubbery";
    std::ofstream outfile(path.c_str());  // fallible

    outfile << tree;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
    throw std::runtime_error("cannot create form without a target");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm&) {
    throw std::runtime_error("cannot assign forms");
}
