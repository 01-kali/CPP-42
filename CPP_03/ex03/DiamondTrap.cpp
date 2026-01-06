#include <DiamondTrap.hpp>

DiamoundTrap::DiamoundTrap():ClapTrap("anonymous" + std::string("_clap_name"))
{
  std::cout << "DiamoundTrap: Default constructor called" << std::endl;
  Name = "anonymous";
  HitPoints = FragTrap::HitPoints;
  EnergyPoints = ScavTrap::EnergyPoints;
  AttackDamage = FragTrap::AttackDamage;
}

DiamoundTrap::DiamoundTrap(std::string name): ClapTrap(name + "_clap_name")
{
  std::cout << "DiamoundTrap: string constructor called" << std::endl;
  Name = name;
  HitPoints = FragTrap::HitPoints;
  EnergyPoints = ScavTrap::EnergyPoints;
  AttackDamage = FragTrap::AttackDamage;
}

DiamoundTrap::DiamoundTrap(const DiamoundTrap &nw) 
    : ClapTrap(nw), ScavTrap(nw), FragTrap(nw){
  std::cout << "DiamoundTrap: Copy constructor called" << std::endl;
  Name = nw.Name;
  HitPoints = nw.FragTrap::HitPoints;
  EnergyPoints = nw.ScavTrap::EnergyPoints;
  AttackDamage = nw.FragTrap::AttackDamage;
}

DiamoundTrap &DiamoundTrap::operator=(const DiamoundTrap &nw)
{
  if(this != &nw)
  {
    ClapTrap::Name = nw.Name + std::string("_clap_name");
    Name = nw.Name;
    HitPoints = nw.FragTrap::HitPoints;
    EnergyPoints = nw.ScavTrap::EnergyPoints;
    AttackDamage = nw.FragTrap::AttackDamage;
  }
  std::cout << "DiamoundTrap: Copy assignment operator called" << std::endl;
  return(*this);
}

DiamoundTrap::~DiamoundTrap()
{
  std::cout << "DiamoundTrap: Destructor called" << std::endl;
}

void DiamoundTrap::attack(const std::string& target)
{
  ScavTrap::attack(target);
}

void DiamoundTrap::whoAmI()
{
  if (EnergyPoints <= 0 || HitPoints <= 0)
  {
    std::cout << "ClapTrap " << Name << " has no hit points or energy points left :(\n";
      return;
  }
  std::cout << "who am i " << ClapTrap::Name << " or " << this->Name << std::endl;
}
