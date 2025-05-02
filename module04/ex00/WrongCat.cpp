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

WrongCat::~WrongCat() {
    LOG_FUNCTION();
}

void WrongCat::makeSound() const {
    std::cout << wrong_cat_sound;
}
