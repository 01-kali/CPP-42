#include <Span.hpp>

int main(){
  {
    std::cout << "Subject test:" << std::endl;
    Span sp1 = Span(5);

    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);

    sp1.print();
    std::cout << " " << sp1.shortestSpan() << std::endl;
    std::cout << " " << sp1.longestSpan() << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Span with 10000 numbers:" << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> test;

    for (int i = 0; i < 10000; i++) test.push_back(i);

    sp2.addMultipleNumbers(test.begin(), test.end());

    std::cout << " The shortest span is: "<< sp2.shortestSpan() << std::endl;
    std::cout << " The longest span is: "<< sp2.longestSpan() << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Exceptions tests :" << std::endl;
    std::cout << " Test 1: Adding to a full Span." << std::endl;
    try {
      Span s1 = Span(1);

      s1.addNumber(4);
      s1.print();
      s1.addNumber(8);
    }
    catch (const std::exception& e) {std::cout << "  " << e.what() << std::endl;}
    std::cout << "\n Test 2: Adding multiple numbers that exceed capacity." << std::endl;
    try {
      Span s1 = Span(5);
      std::vector<int> tmp;

      for (int i = 0; i < 3; i++) {
        s1.addNumber(i);
        tmp.push_back(i);
      }
      s1.print();
      s1.addMultipleNumbers(tmp.begin(), tmp.end());
    }
    catch (const std::exception& e) {std::cout << "  " << e.what() << std::endl;}
    std::cout << "\n Test 3: Calling shortestSpan() with one number." << std::endl;
    try {
      Span s1 = Span(1);

      s1.addNumber(0);
      s1.print();
      s1.shortestSpan();
    }
    catch (const std::exception& e) {std::cout << "  " << e.what() << std::endl;}
    std::cout << "\n Test 4: Calling longestSpan() with one number." << std::endl;
    try {
      Span s1 = Span(1);

      s1.addNumber(0);
      s1.print();
      s1.longestSpan();
    }
    catch (const std::exception& e) {std::cout << "  " << e.what() << std::endl;}
  }
  return 0;
}

