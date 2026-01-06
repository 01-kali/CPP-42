#include <Dog.hpp>

Dog::Dog(): Animal("Dog"){
  brain = new Brain();
  std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std:: string type): Animal(type){
  brain = new Brain();
  std::cout << "Dog: string constructor called" << std::endl;
}

Dog::Dog(Dog &nw): Animal(nw.type){
  std::cout << "Dog: copy constructor called" << std::endl;
  brain = new Brain(*nw.brain);
}

Dog::~Dog(){
  delete brain;
  std::cout << "Dog: deconstructor called" << std::endl;
}

Dog &Dog::operator=(Dog &nw){
  std::cout << "Dog: Copy assignment operator called" << std::endl;
  if (this != &nw){
    brain = new Brain(*nw.brain);
    type = nw.type;
  }
  return (*this);
}

void Dog::makeSound() const{
  std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdeas(int i) const{
  return brain->getIdeas(i);
}

void Dog::setIdeas(int i, std::string idea) const{
  brain->setIdeas(i,idea);
}
