#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array{
private:
  T *arr_;
  unsigned int size_;
public:
  Array():size_(0), arr_(NULL){}

  Array(unsigned int n): size_(n){
    arr_ = new T[size_]();
  }

  Array(const Array &nw): size_(nw.size_){
    arr_ = new T[size_]();
    for (unsigned int i = 0; i < size_ ; i++)
      arr_[i] = nw.arr_[i];
  }

  Array &operator=(const Array &nw){
    if(this != &nw){
      delete[] arr_;
      size_ = nw.size_;
      arr_ = new T[size_]();
      for (unsigned int i = 0; i < size_ ; i++)
        arr_[i] = nw.arr_[i];
    }
    return *this;
  }

  T &operator[](unsigned int n){
    if(n >= size_)
      throw std::exception();
    return arr_[n];
  }
  
  const T &operator[](unsigned int n) const{
    if(n >= size_)
      throw std::exception();
    return arr_[n];
  }

  ~Array(){
    delete[] arr_;
  }
  
  unsigned int size() const{
    return size_;
  }
};

#endif
