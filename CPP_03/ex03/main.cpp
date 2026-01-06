#include <DiamondTrap.hpp>

int main()
{
  DiamoundTrap v1;
  DiamoundTrap v2("CL");
  DiamoundTrap v3(v2);
  v1 = v3;

  std::cout << std::endl;

  v1.attack("target1");
  v2.attack("target2");
  v3.attack("target3");

  std::cout << std::endl;

  v1.takeDamage(1);
  v2.takeDamage(20);
  v3.takeDamage(30);

  std::cout << std::endl;

  v1.beRepaired(10);
  v2.beRepaired(20);
  v3.beRepaired(30);

  std::cout << std::endl;

  v1.highFivesGuys();
  v2.highFivesGuys();
  v3.highFivesGuys();

  std::cout << std::endl;

  v1.guardGate();
  v2.guardGate();
  v3.guardGate();

  std::cout << std::endl;

  v1.whoAmI();
  v2.whoAmI();
  v3.whoAmI();

  std::cout << std::endl;

}
