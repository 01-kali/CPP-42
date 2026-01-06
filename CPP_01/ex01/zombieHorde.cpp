#include <Zombie.hpp>

Zombie* zombieHorde( int N, std::string name )
{
  Zombie *z = new Zombie[N];
  if (!z)
  {
    std::cout << "allocation failed";
    exit(0);
  }
  for (int i = 0; i < N; i++)
    z[i].setName(name);
  return(z);
}
