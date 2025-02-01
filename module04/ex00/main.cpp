#include <string>

class Animal {
   public:
    virtual void makeSound() const = 0;

   protected:
    std::string type;
};

class Dog : protected Animal {};

class Cat : protected Animal {};

int main() {}
