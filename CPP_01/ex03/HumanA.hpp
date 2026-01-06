#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <Weapon.hpp>

class HumanA
{
  private:
    Weapon &wpn;
    std::string name;
  public:
    HumanA(std::string name, Weapon &wpn);
    void attack();
};

#endif
