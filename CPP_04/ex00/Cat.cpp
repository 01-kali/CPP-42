#include <Cat.hpp>

Cat::Cat(): Animal("Cat"){
  std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(std:: string type): Animal(type){
  std::cout << "Cat: string constructor called" << std::endl;
}

Cat::Cat(Cat &nw): Animal(nw.type){
  std::cout << "Cat: copy constructor called" << std::endl;
}

Cat::~Cat(){
  std::cout << "Cat: deconstructor called" << std::endl;
}

Cat &Cat::operator=(Cat &nw){
  std::cout << "Cat: Copy assignment operator called" << std::endl;
  if (this != &nw)
    type = nw.type;
  return (*this);
}

void Cat::makeSound() const{
  std::cout << "Meow!" << std::endl;
}
