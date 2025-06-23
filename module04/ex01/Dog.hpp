#pragma once

#include "Animal.hpp"

class Dog : public Animal {
   public:
    Dog();
    Dog(const Dog& o);
    Dog& operator=(const Dog& o);
    ~Dog();

    void makeSound() const;
};
