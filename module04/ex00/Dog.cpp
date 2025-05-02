#include "Dog.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << '\n'

namespace {
const char* dog_sound = "bork bork\n";
}  // namespace

Dog::Dog() : Animal() {
    LOG_FUNCTION();
    this->type = "Dog";
}

Dog::~Dog() {
    LOG_FUNCTION();
}

void Dog::makeSound() const {
    std::cout << dog_sound;
}
