#include <Character.hpp>

Character::Character(): name("unknown"), size(0){
  for (int i = 0; i < 4; i++)
    inventory[i] = NULL;
}

Character::Character(std::string name): name(name), size(0){
  for (int i = 0; i < 4; i++)
    inventory[i] = NULL;
}

Character::Character(const Character &nw): name(nw.name){
  for (int i = 0; i < 4; i++){
    if (nw.inventory[i] != NULL)
      inventory[i] = nw.inventory[i]->clone();
  }
}

Character::~Character(){
  while (--size >= 0)
    delete collector[size];
  for (int i = 0; i < 4; i++)
    delete inventory[i];
}

Character &Character::operator=(const Character &nw){
  if(this != &nw)
  {
    name = nw.name;
    for (int i = 0; i < 4; i++){
      if (nw.inventory[i] != NULL)
        inventory[i] = nw.inventory[i]->clone();
    }
  }
  return(*this);
}

std::string const & Character::getName() const{
  return(name);
}

void Character::equip(AMateria* m){
  for(int i = 0; i < 4; i++)
  {
    if(inventory[i] == m)
      return;
    if(inventory[i] == NULL){
      inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx){
  if (idx >= 0 && idx <= 3 && inventory[idx] != NULL){
    collector[size++] = inventory[idx];
    inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target){
  if(idx >= 0 && idx < 4 && inventory[idx] != NULL)
    inventory[idx]->use(target);
}
