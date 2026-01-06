#include <Zombie.hpp>

void Zombie::announce( void )
{
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
  this->name = name;
  announce();
}

Zombie::~Zombie()
{
  std::cout << name << ": destroyed" << std::endl;
}
