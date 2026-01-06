#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>

int main()
{
  {
  int noa = 3;
  const Animal* meta[noa];

  for(int i = 0; i < noa; i++){
    meta[i] = new Dog();
    if(i % noa == 0)
    {
      delete meta[i];
      meta[i] = new Cat();
    }
  }
  std::cout << std::endl;
  for(int i = 0; i < noa ; i++)
    delete meta[i];
  }
  {
    std::cout << std::endl;
    std::cout << "set an idea\n" << std::endl;
    
    const Animal* meta;
    const Dog i;
    const Cat j;

    std::cout << std::endl;
    meta = &i;

    i.setIdeas(1, "wow i have an idea!");
    std::cout << meta->getType() << ": " << i.getIdeas(1) << std::endl;
    meta = &j;

    j.setIdeas(1, "wow i have an idea!");
    std::cout << meta->getType() << ": " << j.getIdeas(1) << std::endl;
    std::cout << std::endl;
  }
  return(0);
}
