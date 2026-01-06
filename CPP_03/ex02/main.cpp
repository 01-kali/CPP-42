#include <FragTrap.hpp>

int main()
{
  FragTrap v1;
  FragTrap v2("CL");
  FragTrap v3(v2);
  v1 = v3;

  std::cout << std::endl;

  v1.attack("Target1");
  v2.attack("Target2");
  v3.attack("Target3");

  std::cout << std::endl;

  v1.takeDamage(10);
  v2.takeDamage(50);
  v3.takeDamage(100);

  std::cout << std::endl;

  v1.beRepaired(10);
  v2.beRepaired(50);
  v3.beRepaired(100);

  std::cout << std::endl;

  v1.highFivesGuys();
  v2.highFivesGuys();
  v3.highFivesGuys();

  std::cout << std::endl;
}
