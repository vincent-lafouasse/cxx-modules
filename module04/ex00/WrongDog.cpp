#include "WrongDog.hpp"

#include <iostream>

namespace {
const char* wrong_dog_sound = "bork bork but wrong\n";
}  // namespace

WrongDog::WrongDog() : WrongAnimal() {
    std::cout << "WrongDog created\n";
    this->type = "WrongDog";
}
void WrongDog::makeSound() const {
    std::cout << wrong_dog_sound;
}
