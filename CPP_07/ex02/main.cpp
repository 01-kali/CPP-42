#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 5
int main(int, char**)
{
  Array<int> array(MAX_VAL);
  
  for (int i = 0; i < MAX_VAL; i++)
  {
    array[i] = i;
    std::cout << "\33[34m" << "array[" << i << "]: " << array[i] << "\33[0m" << std::endl;
  }

  std::cout << std::endl 
    << "\33[35m" << "Copy Constructor \"test[]\" & Assignment Operator \"tmp[]\":" 
    << "\33[0m" << std::endl;
  Array<int> tmp = array;
  Array<int> test(tmp);
  for (int i = 0; i < MAX_VAL; i++)
    std::cout << "tmp[" << i << "]: " << tmp[i] 
      << ", test[" << i << "]: " << test[i] << std::endl;
  
  std::cout << std::endl << "\33[35m" << "change \"array[]\": " << "\33[0m" << std::endl;
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++)
  {
    const int value = rand();
    array[i] = value;
    std::cout << "Array[" << i << "]: " << array[i] << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i < MAX_VAL; i++)
  {
    std::cout << "tmp[" << i << "]: " << tmp[i] 
      << ", test[" << i << "]: " << test[i] << std::endl;
  }

  std::cout << std::endl 
    << "\33[35m" << "Operator Overloading \"[]\"" << "\33[0m"
    << std::endl;
  try{
    std::cout << "array[10]" << std::endl;
    array[10] = 0;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << ": 10 > 5" << std::endl;
  }
  try{
    std::cout << "array[3]" << std::endl;
    array[3] = 0;
    std::cerr << "3 < 5" << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
