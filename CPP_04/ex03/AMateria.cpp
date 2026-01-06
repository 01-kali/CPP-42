#include <AMateria.hpp>

AMateria::AMateria(): Type("unknown"){}

AMateria::AMateria(std::string const & type): Type(type){}

AMateria::AMateria(const AMateria &nw): Type(nw.Type){}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(const AMateria &nw){
  if (this != &nw)
    Type = nw.Type;
  return(*this);
}

std::string const & AMateria::getType() const{
  return(Type);
}

void AMateria::use(ICharacter& target){
  std::cout << target.getName() << std::endl;
}
