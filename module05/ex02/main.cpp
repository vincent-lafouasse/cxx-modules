#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

namespace {
void logException(const std::exception& e) {
    std::cout << "Caught exception [" << e.what() << "]";
    std::cout << " from wrecking my stack\n";
}
}  // namespace

int main() {
    Form f("Lobotomy", 42, 69);

    Bureaucrat best("best", 1);
    Bureaucrat worst("worst", 150);

    std::cout << f;
    std::cout << best;
    std::cout << worst;

    worst.signForm(f);
    best.signForm(f);
}
