#include <Brain.hpp>

Brain::Brain(){
  std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(Brain &nw){
  std::cout << "Brain: copy constructor called" << std::endl;
  for(int i = 0; i < 100 ; i++)
    ideas[i] = nw.ideas[i];
}

Brain::~Brain(){
  std::cout << "Brain: deconstructor called" << std::endl;
}

Brain &Brain::operator=(Brain &nw){
  std::cout << "Brain: Copy assignment operator called" << std::endl;
  if(this != &nw)
  {
    for(int i = 0; i < 100 ; i++)
      ideas[i] = nw.ideas[i];
  }
  return(*this);
}
std::string Brain::getIdeas(int i){
  if(i < 0 || i > 99)
    return "Error: index is out of bounds";
  return ideas[i];
}
void Brain::setIdeas(int i, std::string idea){
  if(i < 0 || i > 99){
    std::cout << "Error: index is out of bounds" << std::endl;
    return;
  }
  ideas[i] = idea;
}
