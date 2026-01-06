#include <easyfind.hpp>

int main(){
  std::vector<int> I1;

  I1.push_back(30);
  I1.push_back(3);
  I1.push_back(0);

  std::cout << "I1: ";
  for (std::vector<int>::iterator it = I1.begin(); it != I1.end(); it++) std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "\nTest 1: Should find 0." << std::endl;
  try {
    easyfind(I1,0);
    std::cout << "  SUCCESS: Found 0 in I1." << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
  std::cout << "\nTest 2: Should not find 5." << std::endl;
  try {
    easyfind(I1,5);
    std::cout << "  SUCCESS: Found 0 in I1." << std::endl;
  }
  catch (const std::exception& e) {
    std::cout << "  " << e.what() << std::endl;
  }
  
  return 0;
}
