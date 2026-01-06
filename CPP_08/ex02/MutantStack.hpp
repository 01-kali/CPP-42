#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <vector>
#include <list>

template <typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence>
{
public:
  MutantStack(): std::stack<T, Sequence>(){}
  MutantStack(const MutantStack &nw): std::stack<T, Sequence>(nw){}
  MutantStack &operator=(const MutantStack &nw){
    if(this != &nw){
      std::stack<T, Sequence>::operator=(nw);
    }
    return *this;
  }
  ~MutantStack(){}

  typedef typename std::stack<T, Sequence>::container_type::iterator iterator;
  typedef typename std::stack<T, Sequence>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T, Sequence>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T, Sequence>::container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin(){return this->c.begin();}
  iterator end(){return this->c.end();}
  
  const_iterator begin() const {return this->c.begin();}
  const_iterator end() const {return this->c.end();}
  
  reverse_iterator rbegin(){return this->c.rbegin();}
  reverse_iterator rend(){return this->c.rend();}
  
  const_reverse_iterator rbegin() const {return this->c.rbegin();}
  const_reverse_iterator rend() const {return this->c.rend();}
};

#endif
