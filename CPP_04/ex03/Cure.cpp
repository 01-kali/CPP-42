#include <Cure.hpp>

Cure::Cure(): AMateria("cure"){}

Cure::Cure(std::string const & type): AMateria(type){}

Cure::Cure(const Cure &nw): AMateria(nw.Type){}

Cure::~Cure(){}

Cure &Cure::operator=(const Cure &nw){
  if (this != &nw)
    Type = nw.Type;
  return(*this);
}

AMateria* Cure::clone() const{
  return (new Cure(*this));
}

void Cure::use(ICharacter& target){
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
