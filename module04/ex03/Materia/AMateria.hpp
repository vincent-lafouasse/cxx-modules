#pragma once

#include <string>

class ICharacter;

class AMateria {
   public:
    virtual ~AMateria();

    std::string const& getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

   protected:
    std::string type;

    explicit AMateria(std::string const& type);
    AMateria();
    AMateria(const AMateria& o);
    AMateria& operator=(const AMateria& o);
};
