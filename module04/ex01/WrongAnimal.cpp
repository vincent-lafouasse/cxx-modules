#include "WrongAnimal.hpp"

#include <iostream>

namespace {
const char* generic_wrong_sound = "generic animal sound but wrong\n";
}  // namespace

WrongAnimal::WrongAnimal() : type("Wrongsomething") {
    std::cout << "WrongAnimal created\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    std::cout << "WrongAnimal assigned\n";
    this->type = a.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << generic_wrong_sound;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
