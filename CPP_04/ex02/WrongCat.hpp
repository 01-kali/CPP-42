#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <WrongAnimal.hpp>

class WrongCat: public WrongAnimal{
  public:
    WrongCat();
    WrongCat(std:: string type);
    WrongCat(WrongCat &nw);
    ~WrongCat();

    WrongCat &operator=(WrongCat &nw);
    void makeSound() const;
};

#endif
