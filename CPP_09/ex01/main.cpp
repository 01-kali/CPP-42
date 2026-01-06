#include <RPN.hpp>

int main(int argc, char **argv){
  try {
    if(argc == 2){
      RPN result(argv[1]);
      return 0;
    }
    throw std::invalid_argument("Error: usage ./RPN <expression>");
  }
  catch (const std::exception &e) {std::cerr << e.what() << std::endl; return 1;}
}
