#include <ScavTrap.hpp>

int main()
{
  ScavTrap v1;
  ScavTrap v2("CL");
  ScavTrap v3(v2);
  v1 = v3;
  
  std::cout << std::endl;

  v1.attack("target1");
  v2.attack("target2");
  v3.attack("target3");
  
  std::cout << std::endl;

  v1.takeDamage(10);
  v2.takeDamage(50);
  v3.takeDamage(100);
  
  std::cout << std::endl;
  
  v1.beRepaired(10);
  v2.beRepaired(50);
  v3.beRepaired(100);
  
  std::cout << std::endl;
  
  v1.guardGate();
  v2.guardGate();
  v3.guardGate();
  
  std::cout << std::endl;
}
