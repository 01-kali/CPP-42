#include <BitcoinExchange.hpp>

int main(int argc, char **argv){
  (void)argv;
  try {
    if(argc != 2)
      throw std::invalid_argument("Error: usage ./RPN <Input file>");
    BitcoinExchange be;
    be.BitcoinPrice(argv[1]);
    return 0;
  }
  catch (const std::exception &e) {std::cerr << e.what() << std::endl; return 1;}
}
