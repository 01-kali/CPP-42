#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Dog: public Animal{
  private:
    Brain* brain;
  public:
    Dog();
    Dog(std:: string type);
    Dog(Dog &nw);
    ~Dog();

    Dog &operator=(Dog &nw);
    void makeSound() const;
    std::string getIdeas(int i) const;
    void setIdeas(int i, std::string idea) const;
};

#endif
