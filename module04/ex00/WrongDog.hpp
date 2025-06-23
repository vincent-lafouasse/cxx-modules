#pragma once

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
   public:
    WrongDog();
    WrongDog(const WrongDog& o);
    WrongDog& operator=(const WrongDog& o);
    ~WrongDog();

    void makeSound() const;
};
