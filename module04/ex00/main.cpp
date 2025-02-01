#include <iostream>
#include <string>

namespace {
const char* generic_sound = "generic animal sound\n";
const char* dog_sound = "bork bork\n";
const char* cat_sound = "mrow mrow\n";

const char* generic_wrong_sound = "generic animal sound but wrong\n";
const char* wrong_dog_sound = "bork bork but wrong\n";
const char* wrong_cat_sound = "mrow mrow but wrong\n";
}  // namespace

class Animal {
   public:
    Animal() : type("something") {}
    Animal& operator=(const Animal& a) {
        this->type = a.type;
        return *this;
    }
    virtual void makeSound() const { std::cout << generic_sound; }
    std::string getType() const { return this->type; }

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

class WrongAnimal {
   public:
    WrongAnimal() : type("Wrongsomething") {}
    WrongAnimal& operator=(const WrongAnimal& a) {
        this->type = a.type;
        return *this;
    }
    void makeSound() const { std::cout << generic_wrong_sound; }
    std::string getType() const { return this->type; }

   protected:
    std::string type;
};

class WrongDog : public WrongAnimal {
   public:
    WrongDog() : WrongAnimal() { this->type = "WrongDog"; }
    void makeSound() const { std::cout << wrong_dog_sound; }
};

class WrongCat : public WrongAnimal {
   public:
    WrongCat() : WrongAnimal() { this->type = "WrongCat"; }
    void makeSound() const { std::cout << wrong_cat_sound; }
};

int main() {
    {
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << "dog is a " << dog->getType() << std::endl;
        std::cout << "cat is a " << cat->getType() << std::endl;

        dog->makeSound();
        cat->makeSound();
        animal->makeSound();

        delete dog;
        delete cat;
        delete animal;
    }
    {
        const WrongAnimal* wrong_animal = new WrongAnimal();
        const WrongAnimal* wrong_dog = new WrongDog();
        const WrongAnimal* wrong_cat = new WrongCat();

        std::cout << "wrong_dog is a " << wrong_dog->getType() << std::endl;
        std::cout << "wrong_cat is a " << wrong_cat->getType() << std::endl;

        wrong_dog->makeSound();
        wrong_cat->makeSound();
        wrong_animal->makeSound();

        delete wrong_dog;
        delete wrong_cat;
        delete wrong_animal;
    }
}
