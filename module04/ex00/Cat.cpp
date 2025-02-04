#include "Cat.hpp"

#include <iostream>

namespace {
const char* cat_sound = "mrow mrow\n";
}  // namespace

Cat::Cat() : Animal() {
    std::cout << "Cat created\n";
    this->type = "Cat";
}
Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const {
    std::cout << cat_sound;
}
