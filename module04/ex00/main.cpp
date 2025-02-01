#include <string>

class Animal {
   public:
    Animal() : type("something") {}
    Animal& operator=(const Animal& a) {
        this->type = a.type;
        return *this;
    }
    virtual void makeSound() const;

   protected:
    std::string type;
};

class Dog : public Animal {
   public:
    Dog() : Animal() { this->type = "Dog"; }
};

class Cat : public Animal {
   public:
    Cat() : Animal() { this->type = "Cat"; }
};

int main() {
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
}
