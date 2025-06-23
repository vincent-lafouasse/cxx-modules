#include "Dog.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* dog_sound = "bork bork\n";
}  // namespace

Dog::Dog() : Animal() {
    LOG_FUNCTION();
    this->type = "Dog";
}

Dog::Dog(const Dog& o) : Animal(o) {}

Dog& Dog::operator=(const Dog& o) {
    this->type = o.type;
    return *this;
}

Dog::~Dog() {
    LOG_FUNCTION();
}

void Dog::makeSound() const {
    std::cout << dog_sound;
}
