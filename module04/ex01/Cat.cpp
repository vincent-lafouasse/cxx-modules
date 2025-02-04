#include "Cat.hpp"

#include <iostream>

namespace {
const char* cat_sound = "mrow mrow\n";
}  // namespace

Cat::Cat() : Animal(), brain(new Brain) {
    std::cout << "Cat created\n";
    this->type = "Cat";
}
Cat::~Cat() {
    std::cout << "Cat destroyed\n";
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << cat_sound;
}
