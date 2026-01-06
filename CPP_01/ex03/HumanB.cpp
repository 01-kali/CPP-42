#include <HumanB.hpp>

void HumanB::setWeapon(Weapon &wpn)
{
 this->wpn = &wpn;
}

void HumanB::attack()
{

  if (wpn == NULL)
    std::cout << name << " attacks with no weapon" << std::endl;
  else 
    std::cout << name <<" attacks with their "
      << wpn->getType() << std::endl;
}

HumanB::HumanB(std::string name): wpn(NULL), name(name) {}
