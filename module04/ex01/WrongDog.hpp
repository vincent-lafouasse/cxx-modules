#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
   public:
    WrongDog();
    void makeSound() const;
};
