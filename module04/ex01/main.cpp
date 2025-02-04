#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#define N 4

int main() {
    Animal* animals[N];
    for (std::size_t i = 0; i < N; i++) {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // do stuff

    for (std::size_t i = 0; i < N; i++) {
        delete animals[i];
    }
}
