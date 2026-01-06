#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span{
private:
  std::vector<int> _container;
  unsigned int _maxSize;
public:
  Span();
  Span(unsigned int N);
  Span(const Span &nw);
  Span &operator=(const Span &nw);
  ~Span();

  struct SpanIsFull: std::exception{
    virtual const char* what() const throw();
  };
  struct NoSpanFound: std::exception{
    virtual const char* what() const throw();
  };
  void addNumber(int nw);
  int longestSpan();
  int shortestSpan();

  template <typename T>
    void addMultipleNumbers(T begin, T end){
      int size = std::distance(begin, end);
      if(size + _container.size() > _maxSize)
        throw SpanIsFull();
      _container.insert(_container.end(), begin, end);
    }
  void print();
};

#endif
