#include <Dog.hpp>

Dog::Dog(): Animal("Dog"){
  std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std:: string type): Animal(type){
  std::cout << "Dog: string constructor called" << std::endl;
}

Dog::Dog(Dog &nw): Animal(nw.type){
  std::cout << "Dog: copy constructor called" << std::endl;
}

Dog::~Dog(){
  std::cout << "Dog: deconstructor called" << std::endl;
}

Dog &Dog::operator=(Dog &nw){
  std::cout << "Dog: Copy assignment operator called" << std::endl;
  if (this != &nw)
    type = nw.type;
  return (*this);
}

void Dog::makeSound() const{
  std::cout << "Woof!" << std::endl;
}

