#pragma once

#include <string>

class Animal {
   public:
    virtual ~Animal();

    virtual void makeSound() const = 0;
    std::string getType() const;

   protected:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& a);

    std::string type;
};
