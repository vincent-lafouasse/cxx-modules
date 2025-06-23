#pragma once

#include <string>

class Brain {
   public:
    Brain();
    Brain(const Brain& o);
    Brain& operator=(const Brain& o);
    ~Brain();

   private:
    static const std::size_t nIdeas = 100;
    std::string ideas[Brain::nIdeas];
};
