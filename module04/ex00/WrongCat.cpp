#include "WrongCat.hpp"

#include <iostream>

#define LOG_FUNCTION() \
    std::clog << __PRETTY_FUNCTION__ << '\n'

namespace {
const char* wrong_cat_sound = "mrow mrow but wrong\n";
}  // namespace

WrongCat::WrongCat() : WrongAnimal() {
    LOG_FUNCTION();
    this->type = "WrongCat";
}
void WrongCat::makeSound() const {
    std::cout << wrong_cat_sound;
}
