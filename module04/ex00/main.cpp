#include <iostream>
#include <string>

namespace {
const char* generic_sound = "generic animal sound\n";
const char* dog_sound = "bork bork\n";
const char* cat_sound = "mrow mrow\n";
}  // namespace

class Animal {
   public:
    Animal() : type("something") {}
    Animal& operator=(const Animal& a) {
        this->type = a.type;
        return *this;
    }
    virtual void makeSound() const { std::cout << generic_sound; }

   protected:
    std::string type;
};

class Dog : public Animal {
   public:
    Dog() : Animal() { this->type = "Dog"; }
    void makeSound() const { std::cout << dog_sound; }
};

class Cat : public Animal {
   public:
    Cat() : Animal() { this->type = "Cat"; }
    void makeSound() const { std::cout << cat_sound; }
};

int main() {
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
}
