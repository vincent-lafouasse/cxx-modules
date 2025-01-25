#pragma once

#include <string>

class Zombie {
   public:
    Zombie();
    ~Zombie();
    void announce() const;
    void set_name(const std::string& name);

   private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);
