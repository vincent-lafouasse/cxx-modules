#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
   public:
    FragTrap();
    FragTrap(const FragTrap&);
    FragTrap& operator=(const FragTrap&);
    ~FragTrap();

    explicit FragTrap(const std::string& name);
    void attack(const std::string& target);
    void highFivesGuys() const;

   protected:
    static const char* default_name;
    static const uint32_t base_hp;
    static const uint32_t base_energy;
    static const uint32_t base_attack;
};
