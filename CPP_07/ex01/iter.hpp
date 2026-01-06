#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, const size_t size, void (*func)(T&)){
  if(arr == NULL || func == NULL) return;
  for (size_t i = 0; i < size; i++) func(arr[i]);
}

template <typename T>
void iter(T const *arr, const size_t size, void (*func)(T const &)){
  if(arr == NULL || func == NULL) return;
  for (size_t i = 0; i < size; i++) func(arr[i]);
}

#endif
