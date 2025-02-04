#pragma once

#include <string>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& a);

    void makeSound() const;
    std::string getType() const;

   protected:
    std::string type;
};
