#pragma once

#include <string>

class Harl {
   public:
    void complain(std::string level);

   private:
    void debug() const;
    void info() const;
    void warning() const;
    void error() const;
};
