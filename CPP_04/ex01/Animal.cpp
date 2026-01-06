#include <Animal.hpp>


Animal::Animal(){
  std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std:: string type): type(type){
  std::cout << "Animal: string constructor called" << std::endl;
}

Animal::Animal(Animal &nw){
  std::cout << "Animal: copy constructor called" << std::endl;
  type = nw.type;
}

Animal::~Animal(){
  std::cout << "Animal: deconstructor called" << std::endl;
}

Animal &Animal::operator=(Animal &nw){
  std::cout << "Animal: Copy assignment operator called" << std::endl;
  if (this != &nw)
    type = nw.type;
  return (*this);
}

std::string Animal::getType() const{
  return(type);
}

void Animal::makeSound() const{
  std::cout << "Generic animal sound" << std::endl;
}
