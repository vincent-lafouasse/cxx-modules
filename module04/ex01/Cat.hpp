#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    ~Cat();

    void makeSound() const;

   private:
    Brain* brain;
};
