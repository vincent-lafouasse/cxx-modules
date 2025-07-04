#include <iostream>

#include "Bureaucrat.hpp"

namespace {
void logException(const std::exception& e) {
    std::cout << "Caught exception [" << e.what() << "]";
    std::cout << " from wrecking my stack\n";
}
}  // namespace

int main() {
    const std::string name("poss");

    Bureaucrat a(name, 69);
    std::cout << a;

    Bureaucrat b(name, 1);
    std::cout << b;
    try {
        b.moveUp();
    } catch (const std::exception& e) {
        logException(e);
    }

    Bureaucrat c(name, 150);
    std::cout << c;
    try {
        c.moveDown();
    } catch (const std::exception& e) {
        logException(e);
    }

    try {
        Bureaucrat nobody(name, 0);
    } catch (const std::exception& e) {
        logException(e);
    }

    try {
        Bureaucrat nobody(name, 151);
    } catch (const std::exception& e) {
        logException(e);
    }

    try {
        Bureaucrat nobody(name, 255);
    } catch (const std::exception& e) {
        logException(e);
    }
}
