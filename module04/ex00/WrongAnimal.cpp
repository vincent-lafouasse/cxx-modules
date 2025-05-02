#include "WrongAnimal.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* generic_wrong_sound = "generic animal sound but wrong\n";
}  // namespace

WrongAnimal::WrongAnimal() : type("Wrongsomething") {
    LOG_FUNCTION();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    LOG_FUNCTION();
    this->type = a.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    LOG_FUNCTION();
}

void WrongAnimal::makeSound() const {
    std::cout << generic_wrong_sound;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
