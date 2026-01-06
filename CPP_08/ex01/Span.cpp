#include <Span.hpp>


Span::Span():_maxSize(0){}

Span::Span(unsigned int N): _maxSize(N){}

Span::Span(const Span &nw):_container(nw._container), _maxSize(nw._maxSize){}

Span &Span::operator=(const Span &nw){
  if(this != &nw){
    _maxSize = nw._maxSize;
    _container = nw._container;
  }
  return *this;
}

Span::~Span(){}

void Span::addNumber(int nw){
  if(_container.size() >= _maxSize)
    throw SpanIsFull();
  _container.push_back(nw);
}

int Span::longestSpan(){
  if(_container.size() < 2)
    throw NoSpanFound();
  std::vector<int>::iterator min = std::min_element(_container.begin(), _container.end());
  std::vector<int>::iterator max = std::max_element(_container.begin(), _container.end());
  return *max - *min;
}

int Span::shortestSpan(){
  int span;
  int shSpan = 0;
  std::vector<int> tmp = _container;

  if(_container.size() < 2)
    throw NoSpanFound();
  std::sort(tmp.begin(), tmp.end());
  shSpan = *(tmp.begin() + 1) - *tmp.begin();
  for(std::vector<int>::iterator it = tmp.begin() + 2; it != tmp.end(); it++){
    span = *it - *(it - 1);
    if(span < shSpan)
      shSpan = span;
  }
  return shSpan;
}

void Span::print(){
  std::cout << "_container content: ";
  for(std::vector<int>::iterator it = _container.begin(); it != _container.end(); it++) std::cout << *it << " ";
  std::cout << std::endl;
}

const char* Span::SpanIsFull::what() const throw(){
  return "Error: Span is full. Cannot add number.";
}

const char* Span::NoSpanFound::what() const throw(){
  return "Error: No span found. (0 or 1 elements)";
}
