#pragma once

#include <string>

class Weapon {
   public:
    const std::string& getType() const { return type; }
    void setType(const std::string& type) { this->type = type; }

   private:
    std::string type;
};
