#include <string>

class Animal {
   public:
    Animal() : type("something") {}
    virtual void makeSound() const;

   protected:
    std::string type;
};

class Dog : protected Animal {
   public:
    Dog() : Animal() { this->type = "Dog"; }
};

class Cat : protected Animal {
    Cat() : Animal() { this->type = "Cat"; }
};

int main() {
    Animal* animal = new Animal();
}
