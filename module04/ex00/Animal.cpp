#include "Animal.hpp"

#include <iostream>

namespace {
const char* generic_sound = "generic animal sound\n";
}  // namespace

Animal::Animal() : type("something") {
    std::cout << "Animal created\n";
}
Animal& Animal::operator=(const Animal& a) {
    std::cout << "Animal assigned\n";
    this->type = a.type;
    return *this;
}
Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

void Animal::makeSound() const {
    std::cout << generic_sound;
}
std::string Animal::getType() const {
    return this->type;
}
