#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <algorithm>
#include <iostream>

struct NotFound: public std::exception{
  virtual const char* what() const throw(){
    return "Element not found in container.";
  }
};

template <typename T>
void easyfind(T& container, int tofind){
  if(std::find(container.begin(), container.end(), tofind) == container.end())
    throw NotFound();
}

#endif
