#ifndef DIAMOUNDTRAP_HPP
#define DIAMOUNDTRAP_HPP

#include <FragTrap.hpp>
#include <ScavTrap.hpp>

class DiamoundTrap:public ScavTrap, public FragTrap
{
  private:
    std::string Name;
  public:
    DiamoundTrap();
    DiamoundTrap(std::string name);
    DiamoundTrap(const DiamoundTrap &nw);
    DiamoundTrap &operator=(const DiamoundTrap &nw);
    ~DiamoundTrap();

    void attack(const std::string& target);
    void whoAmI();
};

#endif
