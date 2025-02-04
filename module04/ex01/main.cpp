#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

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
