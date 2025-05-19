#pragma once

#include <string>

class ICharacter;

class AMateria {
   protected:
    AMateria() {}

    std::string type;

   public:
    explicit AMateria(std::string const& type) : type(type) {}
    std::string const& getType() const { return this->type; }
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};
