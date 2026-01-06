#include <ClapTrap.hpp>

int main()
{
  ClapTrap v1;
  ClapTrap v2("CL");
  ClapTrap v3(v2);
  v1 = v3;

  std::cout << std::endl;

  v1.attack("Target1");
  v2.attack("Target2");
  v3.attack("Target3");

  std::cout << std::endl;
  
  v1.takeDamage(5);
  v2.takeDamage(10);
  v3.takeDamage(20);

  std::cout << std::endl;
  
  v1.beRepaired(10);
  v2.beRepaired(10);
  v3.beRepaired(10);

  std::cout << std::endl;

  return 0;
}
