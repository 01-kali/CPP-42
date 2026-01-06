#include <MateriaSource.hpp>

MateriaSource::MateriaSource(){
  for (int i = 0; i < 4; i++)
    inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &nw){
  for (int i = 0; i < 4; i++){
    if (nw.inventory[i] != NULL)
      inventory[i] = nw.inventory[i]->clone();
    else
      inventory[i] = NULL;
  }
}

MateriaSource::~MateriaSource(){
  for (int i = 0; i < 4 ; i++)
    delete inventory[i];
}


MateriaSource &MateriaSource::operator=(const MateriaSource &nw){
  if(this != &nw)
  {
    for (int i = 0; i < 4; i++){
      if (nw.inventory[i] != NULL)
        inventory[i] = nw.inventory[i]->clone();
    }
  }
  return(*this);
}


void MateriaSource::learnMateria(AMateria* m){
  if(m == NULL)
    return;
  for (int i = 0; i < 4; i++)
  {
    if(inventory[i] == NULL){
      inventory[i] = m->clone();
      delete m;
      return;
    }
  }
  delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type){
  for (int i = 0; i < 4 ; i++){
    if(inventory[i] != NULL && inventory[i]->getType() == type)
      return (inventory[i]->clone());
  }
  return(0);
}
