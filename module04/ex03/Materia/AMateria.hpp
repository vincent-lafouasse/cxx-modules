#pragma once

#include <string>

class ICharacter;

class AMateria {
   public:
    explicit AMateria(std::string const& type) : type(type) {}

    std::string const& getType() const { return this->type; }

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

   protected:
    std::string type;

    AMateria() {}
    AMateria(const AMateria& o) : type(o.type) {}
    AMateria& operator=(const AMateria& o) {
        this->type = o.type;
        return *this;
    }
};
