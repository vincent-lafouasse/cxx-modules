#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

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
}
