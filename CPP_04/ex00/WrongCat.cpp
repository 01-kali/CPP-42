#include <WrongCat.hpp>

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
  std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(std:: string type): WrongAnimal(type){
  std::cout << "WrongCat: string constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &nw): WrongAnimal(nw.type){
  std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
  std::cout << "WrongCat: deconstructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &nw){
  std::cout << "WrongCat: Copy assignment operator called" << std::endl;
  if (this != &nw)
    type = nw.type;
  return (*this);
}

void WrongCat::makeSound() const{
  std::cout << "Meow!" << std::endl;
}
