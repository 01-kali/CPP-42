#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongCat.hpp>

int main()
{
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    delete meta;
    delete i;
    delete j;
  }
  {
    std::cout << std::endl << "Test WrongAnimal and WrongCat" << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;
    i->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    delete meta;
    delete i;
  }
  return(0);
}
