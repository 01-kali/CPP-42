#ifndef ICE_HPP
#define ICE_HPP

#include <AMateria.hpp>

class Ice: public AMateria
{
  public:
    Ice();
    Ice(std::string const & type);
    Ice(const Ice &nw);
    ~Ice();
    
    Ice &operator=(const Ice &nw);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
