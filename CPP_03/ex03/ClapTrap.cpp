#include <ClapTrap.hpp>

ClapTrap::ClapTrap(): Name("anonymous"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
  std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), HitPoints(10), EnergyPoints(10), 
  AttackDamage(0)
{
  std::cout << "ClapTrap: string constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int HitPoints, int EnergyPoints, int AttackDamage):
  Name(name), HitPoints(HitPoints), EnergyPoints(EnergyPoints), AttackDamage(AttackDamage)
{
  std::cout << "ClapTrap: constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &nw): Name(nw.Name), HitPoints(nw.HitPoints), 
  EnergyPoints(nw.EnergyPoints), AttackDamage(nw.AttackDamage)
{
  std::cout << "ClapTrap: Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &nw)
{
  std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
  if(this !=&nw)
  {
    Name = nw.Name;
    HitPoints = nw.HitPoints;
    EnergyPoints = nw.EnergyPoints;
    AttackDamage = nw.AttackDamage;
  }
  return(*this);
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap: Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ClapTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "ClapTrap " << Name
    << " attacks " << target
    << ", causing " << AttackDamage << " points of damage!\n";
  EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ClapTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "ClapTrap " << Name
    << " lose " << amount << " Hit points!\n";
  HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ClapTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "ClapTrap " << Name
    << " gets " << amount << " Hit points!\n";
  HitPoints += amount;
  EnergyPoints--;
}
