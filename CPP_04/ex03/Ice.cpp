#include <Ice.hpp>

Ice::Ice(): AMateria("ice"){}

Ice::Ice(std::string const & type): AMateria(type){}

Ice::Ice(const Ice &nw): AMateria(nw.Type){}

Ice::~Ice(){}

Ice &Ice::operator=(const Ice &nw){
  if (this != &nw)
    Type = nw.Type;
  return(*this);
}

AMateria* Ice::clone() const{
  return (new Ice(*this));
}

void Ice::use(ICharacter& target){
  std::cout << "* shoots an ice bolt at " << target.getName()  << " *"<< std::endl;
}
