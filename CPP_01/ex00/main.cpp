#include <Zombie.hpp>


int main()
{
  randomChump("Fii");
  Zombie *z1 = newZombie("Foo");
  z1->announce();
  delete z1;
  return(0);
}
