#include "Dog.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* dog_sound = "bork bork\n";
}  // namespace

Dog::Dog() : Animal(), brain(new Brain()) {
    LOG_FUNCTION();
    this->type = "Dog";
}

Dog::Dog(const Dog& o) : Animal(o), brain(o.brain) {}

Dog& Dog::operator=(const Dog& o) {
    if (this != &o) {
        this->type = o.type;
        this->brain = o.brain;
    }
    return *this;
}

Dog::~Dog() {
    LOG_FUNCTION();
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << dog_sound;
}
