#include "Animal.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << '\n'

namespace {
const char* generic_sound = "generic animal sound\n";
}  // namespace

Animal::Animal() : type("something") {
    LOG_FUNCTION();
}
Animal& Animal::operator=(const Animal& a) {
    LOG_FUNCTION();
    this->type = a.type;
    return *this;
}
Animal::~Animal() {
    LOG_FUNCTION();
}

void Animal::makeSound() const {
    std::cout << generic_sound;
}
std::string Animal::getType() const {
    return this->type;
}
