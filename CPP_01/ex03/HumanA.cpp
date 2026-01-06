#include <HumanA.hpp>

HumanA::HumanA(std::string name, Weapon &wpn): wpn(wpn), name(name) {}

void HumanA::attack()
{
  std::cout << name <<" attacks with their "
    << wpn.getType() << std::endl;
}
