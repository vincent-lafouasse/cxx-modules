#include "WrongCat.hpp"

#include "LogFunction.hpp"

#include <iostream>

namespace {
const char* wrong_cat_sound = "mrow mrow but wrong\n";
}  // namespace

WrongCat::WrongCat() : WrongAnimal() {
    LOG_FUNCTION();
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& o) : WrongAnimal(o) {
    LOG_FUNCTION();
}

WrongCat& WrongCat::operator=(const WrongCat& o) {
    this->type = o.type;
    return *this;
}

WrongCat::~WrongCat() {
    LOG_FUNCTION();
}

void WrongCat::makeSound() const {
    std::cout << wrong_cat_sound;
}
