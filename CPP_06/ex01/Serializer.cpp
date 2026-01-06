#include <Serializer.hpp>

Serializer::Serializer(){}
Serializer::Serializer(const Serializer &nw){*this = nw;}
Serializer::~Serializer(){}
Serializer &Serializer::operator=(const Serializer &nw){
  (void)nw;
  return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
  return reinterpret_cast<Data*>(raw);
}
