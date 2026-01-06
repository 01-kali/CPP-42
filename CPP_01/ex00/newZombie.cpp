#include <Zombie.hpp>

Zombie* newZombie( std::string name )
{
  Zombie *z;

  z = new Zombie(name);
  if (!z)
  {
    std::cout << "allocation failed" << std::endl;
    exit(0);
  }
  return(z);
}
