#pragma once

#include <string>

class AMateria;

class IMateriaSource {
   public:
    virtual ~IMateriaSource();
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;

   protected:
    IMateriaSource();
    IMateriaSource(const IMateriaSource&);
    IMateriaSource& operator=(const IMateriaSource&);
};
