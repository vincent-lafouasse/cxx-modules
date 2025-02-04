#include "WrongCat.hpp"

#include <iostream>

namespace {
const char* wrong_cat_sound = "mrow mrow but wrong\n";
}  // namespace

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat created\n";
    this->type = "WrongCat";
}
void WrongCat::makeSound() const {
    std::cout << wrong_cat_sound;
}
