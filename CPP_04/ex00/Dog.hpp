#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>

class Dog: public Animal{
  public:
    Dog();
    Dog(std:: string type);
    Dog(Dog &nw);
    ~Dog();

    Dog &operator=(Dog &nw);
    void makeSound() const;
};

#endif
