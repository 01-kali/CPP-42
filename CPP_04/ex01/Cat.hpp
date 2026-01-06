#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Cat: public Animal{
  private:
    Brain* brain;
  public:
    Cat();
    Cat(std:: string type);
    Cat(Cat &nw);
    ~Cat();

    Cat &operator=(Cat &nw);
    void makeSound() const;
    std::string getIdeas(int i) const;
    void setIdeas(int i, std::string idea) const;
};

#endif
