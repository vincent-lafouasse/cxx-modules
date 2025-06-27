#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   public:
    MateriaSource();
    MateriaSource(const MateriaSource&);
    MateriaSource& operator=(const MateriaSource&);
    ~MateriaSource();

    void learnMateria(AMateria*);
    AMateria* createMateria(const std::string& type);

   private:
    static const std::size_t inventorySize = 4;
    AMateria* inventory[inventorySize];

    void clearInventory();
};
