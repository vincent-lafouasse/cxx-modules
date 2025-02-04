#include <iostream>
#include <string>

#include "Cat.hpp"
#include "Dog.hpp"

namespace {
const char* generic_wrong_sound = "generic animal sound but wrong\n";
const char* wrong_dog_sound = "bork bork but wrong\n";
const char* wrong_cat_sound = "mrow mrow but wrong\n";
}  // namespace

class WrongAnimal {
   public:
    WrongAnimal() : type("Wrongsomething") {
        std::cout << "WrongAnimal created\n";
    }
    WrongAnimal& operator=(const WrongAnimal& a) {
        std::cout << "WrongAnimal assigned\n";
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
    WrongDog() : WrongAnimal() {
        std::cout << "WrongDog created\n";
        this->type = "WrongDog";
    }
    void makeSound() const { std::cout << wrong_dog_sound; }
};

class WrongCat : public WrongAnimal {
   public:
    WrongCat() : WrongAnimal() {
        std::cout << "WrongCat created\n";
        this->type = "WrongCat";
    }
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
