#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <ClapTrap.hpp>

class FragTrap: virtual public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &nw);
    FragTrap &operator=(const FragTrap &nw);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif
