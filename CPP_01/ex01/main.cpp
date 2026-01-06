#include <Zombie.hpp>

int main()
{
  Zombie *z = zombieHorde(10, "flillo");
  delete[] z;
  return(0);
}
