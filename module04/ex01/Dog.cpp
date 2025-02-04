#include "Dog.hpp"

#include <iostream>

namespace {
const char* dog_sound = "bork bork\n";
}  // namespace

Dog::Dog() : Animal() {
    std::cout << "Dog created\n";
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << dog_sound;
}
