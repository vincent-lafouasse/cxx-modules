#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal* pen[6];
    const std::size_t sz = sizeof(pen) / sizeof(*pen);

    for (std::size_t i = 0; i < sz; ++i) {
        if (i % 2 == 0) {
            pen[i] = new Dog();
        } else {
            pen[i] = new Cat();
        }
    }

    for (std::size_t i = 0; i < sz; ++i) {
        delete pen[i];
    }
}
