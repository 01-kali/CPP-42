#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange{
private:
  std::map<std::string, float> data_;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &nw);
  BitcoinExchange &operator=(const BitcoinExchange &nw);
  ~BitcoinExchange();

  void BitcoinPrice(std::string data_base);

};

#endif
