#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data{
  uintptr_t i;
};

class Serializer{
  private:
    Serializer();
    Serializer(const Serializer &nw);
    Serializer &operator=(const Serializer &nw);
    ~Serializer();
  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
