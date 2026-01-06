#include <Weapon.hpp>

const std::string &Weapon::getType()
{
  return(type);
}

void Weapon::setType(std::string newType)
{
  type = newType;
}

Weapon::Weapon(std::string str)
{
  type = str;
}

Weapon::Weapon() {}
