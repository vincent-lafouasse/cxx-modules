#pragma once

#include <string>

class Animal {
   public:
    Animal();
    Animal& operator=(const Animal& a);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

   protected:
    std::string type;
};
