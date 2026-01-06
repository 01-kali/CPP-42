#ifndef MATERIASource
#define MATERIASource

#include <IMateriaSource.hpp>

class MateriaSource: public IMateriaSource{
  private:
    AMateria *inventory[4];
  public:
    MateriaSource();
    MateriaSource(const MateriaSource &nw);
    ~MateriaSource();
    
    MateriaSource &operator=(const MateriaSource &nw);
    
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
