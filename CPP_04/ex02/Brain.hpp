#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <Animal.hpp>

class Brain{
  private:
    std::string ideas[100];
  public:
    Brain();
    Brain(Brain &nw);
    ~Brain();
    
    Brain &operator=(Brain &nw);

    std::string getIdeas(int i);
    void setIdeas(int i, std::string idea);
};

#endif
