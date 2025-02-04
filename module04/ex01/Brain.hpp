#pragma once

#include <string>

#define N_IDEAS 100

class Brain {
   public:
    Brain();
    ~Brain();

   private:
    std::string ideas[N_IDEAS];
};
