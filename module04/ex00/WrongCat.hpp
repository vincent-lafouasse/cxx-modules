#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat();
    WrongCat(const WrongCat& o);
    WrongCat& operator=(const WrongCat& o);
    ~WrongCat();
    void makeSound() const;
};
