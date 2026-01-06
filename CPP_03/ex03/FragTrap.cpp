#include <FragTrap.hpp>
    
FragTrap::FragTrap()
{
  Name = "anonymous";
  HitPoints = 100;
  EnergyPoints = 100;
  AttackDamage = 30;
  std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
  Name = name;
  HitPoints = 100;
  EnergyPoints = 100;
  AttackDamage = 30;
  std::cout << "FragTrap: string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &nw): ClapTrap(nw)
{
  std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &nw)
{
  std::cout << "FragTrap: Copy assignment operator called" << std::endl;
  if(this != &nw)
  {
    Name = nw.Name;
    HitPoints = nw.HitPoints;
    EnergyPoints = nw.EnergyPoints;
    AttackDamage = nw.AttackDamage;
  }
  return(*this);
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "FragTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "High five?\n";
}
