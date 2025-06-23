#pragma once

#include "Animal.hpp"

#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& o);
    Cat& operator=(const Cat& o);
    ~Cat();

    void makeSound() const;

   private:
    Brain* brain;
};
