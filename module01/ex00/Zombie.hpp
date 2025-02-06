#pragma once

#include <string>

class Zombie {
   public:
    explicit Zombie(const std::string& name);
    ~Zombie();
    void announce() const;

   private:
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
