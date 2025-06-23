#pragma once

#include <string>

class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& a);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

   protected:
    std::string type;
};
