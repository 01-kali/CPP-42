#include <ScavTrap.hpp>

ScavTrap::ScavTrap(): ClapTrap("anonymous", 100, 50, 20)
{
  std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
  std::cout << "ScavTrap: string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &nw): ClapTrap(nw)
{
  std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &nw)
{
  std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
  if(this !=&nw)
  {
    Name = nw.Name;
    HitPoints = nw.HitPoints;
    EnergyPoints = nw.EnergyPoints;
    AttackDamage = nw.AttackDamage;
  }
  return(*this);
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ScavTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "ScavTrap " << Name
    << " attacks " << target
    << ", causing " << AttackDamage << " points of damage!\n";
  EnergyPoints--;
}

void ScavTrap::guardGate()
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ScavTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "ScavTrap " << Name << " is now in Gate keeper mode\n";
}

