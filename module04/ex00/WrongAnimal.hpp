#pragma once

#include <string>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& o);
    WrongAnimal& operator=(const WrongAnimal& a);
    virtual ~WrongAnimal();

    void makeSound() const;  // not virtual
    std::string getType() const;

   protected:
    std::string type;
};
