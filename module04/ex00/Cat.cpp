#include "Cat.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << '\n'

namespace {
const char* cat_sound = "mrow mrow\n";
}  // namespace

Cat::Cat() : Animal() {
    LOG_FUNCTION();
    this->type = "Cat";
}
Cat::~Cat() {
    LOG_FUNCTION();
}

void Cat::makeSound() const {
    std::cout << cat_sound;
}
