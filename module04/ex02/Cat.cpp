#include "Cat.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* cat_sound = "mrow mrow\n";
}  // namespace

Cat::Cat() : Animal(), brain(new Brain()) {
    LOG_FUNCTION();
    this->type = "Cat";
}

Cat::Cat(const Cat& o) : Animal(o), brain(o.brain) {}

Cat& Cat::operator=(const Cat& o) {
    if (this != &o) {
        this->type = o.type;
        this->brain = o.brain;
    }
    return *this;
}

Cat::~Cat() {
    LOG_FUNCTION();
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << cat_sound;
}
