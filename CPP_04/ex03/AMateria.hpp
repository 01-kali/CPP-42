#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include <ICharacter.hpp>
#include <Character.hpp>
#include <IMateriaSource.hpp>
#include <MateriaSource.hpp>

class AMateria
{
  protected:
    std::string Type;
  public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &nw);
    AMateria &operator=(const AMateria &nw);
    virtual ~AMateria();

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
