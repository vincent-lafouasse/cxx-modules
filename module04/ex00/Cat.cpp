#include "Cat.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* cat_sound = "mrow mrow\n";
}  // namespace

Cat::Cat() : Animal() {
    LOG_FUNCTION();
    this->type = "Cat";
}

Cat::Cat(const Cat& o) : Animal(o) {}

Cat& Cat::operator=(const Cat& o) {
    this->type = o.type;
    return *this;
}

Cat::~Cat() {
    LOG_FUNCTION();
}

void Cat::makeSound() const {
    std::cout << cat_sound;
}
