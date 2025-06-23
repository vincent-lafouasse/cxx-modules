#include "WrongDog.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* wrong_dog_sound = "bork bork but wrong\n";
}  // namespace

WrongDog::WrongDog() : WrongAnimal() {
    LOG_FUNCTION();
    this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog& o) : WrongAnimal(o) {
    LOG_FUNCTION();
}

WrongDog& WrongDog::operator=(const WrongDog& o) {
    this->type = o.type;
    return *this;
}

WrongDog::~WrongDog() {
    LOG_FUNCTION();
}

void WrongDog::makeSound() const {
    std::cout << wrong_dog_sound;
}
