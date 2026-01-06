#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <Weapon.hpp>

class HumanB
{
  private:
    Weapon *wpn;
    std::string name;
  public:
    HumanB(std::string name);
    void setWeapon(Weapon &wpn);
    void attack();
};

#endif
