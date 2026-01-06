#include <iter.hpp>


template <typename T>
void increment(T &x){x++;}

template <typename T>
void print(T const &x){
  std::cout << "Value: " << x << ", Address: " << &x << std::endl;
}

int main(){
  char arrchar[] = {'a', 'b', 'c'};
  const int arrint[] = {1, 2 ,3};

  std::cout << "\033[35m" << std::endl <<  "(non-const array, modifying function):" << "\033[0m" << std::endl;
  std::cout << "\033[33m" << "before:" << "\033[0m" << std::endl;

  for (long unsigned int i = 0; i < sizeof(arrchar) / sizeof(*arrchar); i++)
    std::cout  << "arrchar[" << i << "] = " << arrchar[i] << std::endl;
  

  iter<char>(arrchar, sizeof(arrchar) / sizeof(*arrchar), increment<char>);

  std::cout << "\033[33m" << std::endl << "after:" << "\033[0m" << std::endl;

  for (long unsigned int i = 0; i < sizeof(arrchar) / sizeof(*arrchar); i++)
    std::cout << "arrchar[" << i << "] = " << arrchar[i] << std::endl;

  std::cout << "\033[35m" << std::endl <<  "(const array, read-only function):" << "\033[0m" << std::endl;

  iter<int>(arrint, sizeof(arrint) / sizeof(*arrint), print<int>);

  return 0;
}
