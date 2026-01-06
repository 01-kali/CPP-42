#include <Cat.hpp>

Cat::Cat(): Animal("Cat"){
  brain = new Brain();
  std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(std:: string type): Animal(type){
  brain = new Brain();
  std::cout << "Cat: string constructor called" << std::endl;
}

Cat::Cat(Cat &nw): Animal(nw.type){
  std::cout << "Cat: copy constructor called" << std::endl;
  brain = new Brain(*nw.brain);
}

Cat::~Cat(){
  delete brain;
  std::cout << "Cat: deconstructor called" << std::endl;
}

Cat &Cat::operator=(Cat &nw){
  std::cout << "Cat: Copy assignment operator called" << std::endl;
  if (this != &nw){
    brain = new Brain(*nw.brain);
    type = nw.type;
  }
  return (*this);
}

void Cat::makeSound() const{
  std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdeas(int i) const{
  return brain->getIdeas(i);
}

void Cat::setIdeas(int i, std::string idea) const{
  brain->setIdeas(i,idea);
}
