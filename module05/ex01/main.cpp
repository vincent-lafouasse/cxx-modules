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

    std::cout << f;
}
