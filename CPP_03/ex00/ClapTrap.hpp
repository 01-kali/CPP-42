#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  private:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;
  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string name, int HitPoints, int EnergyPoints, int AttackDamage);
    ClapTrap(const ClapTrap &nw);
    ClapTrap &operator=(const ClapTrap &nw);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
