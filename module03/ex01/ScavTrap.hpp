#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    ScavTrap();
    ScavTrap(const ScavTrap&);
    ScavTrap& operator=(const ScavTrap&);
    ~ScavTrap();

    ScavTrap(const std::string& name);
    void attack(const std::string& target);
    void takeDamage(uint32_t amount);
    void beRepaired(uint32_t amount);
    void guard_guate() const;

   private:
    bool isGuarding;
};
