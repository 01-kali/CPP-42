#include <WrongAnimal.hpp>


WrongAnimal::WrongAnimal(){
  std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std:: string type): type(type){
  std::cout << "WrongAnimal: string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &nw){
  std::cout << "WrongAnimal: copy constructor called" << std::endl;
  type = nw.type;
}

WrongAnimal::~WrongAnimal(){
  std::cout << "WrongAnimal: deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &nw){
  std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
  if (this != &nw)
    type = nw.type;
  return (*this);
}

std::string WrongAnimal::getType() const{
  return(type);
}

void WrongAnimal::makeSound() const{
  std::cout << "Generic animal sound" << std::endl;
}

