#include <PmergeMe.hpp>

int main(int argc, char **argv){
  try {
    if(argc >= 2){
      PmergeMe sort(argv);
      return 0;
    }
    throw std::invalid_argument("Error: At least one number required to perform a sort");
  }
  catch (const std::exception &e) {std::cerr << e.what() << std::endl; return 1;}
}
