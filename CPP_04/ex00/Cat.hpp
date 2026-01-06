#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>

class Cat: public Animal{
  public:
    Cat();
    Cat(std:: string type);
    Cat(Cat &nw);
    ~Cat();

    Cat &operator=(Cat &nw);
    void makeSound() const;
};

#endif
