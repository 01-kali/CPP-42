#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename Y> void swap(Y &x, Y &y){
  Y z;
  z = x;
  x = y;
  y = z;
}

template <typename T> T min(T a, T b){
  return (b <= a) ? b : a;
}

template <typename T> T max(T a, T b){
  return (b >= a) ? b : a;
}


#endif
