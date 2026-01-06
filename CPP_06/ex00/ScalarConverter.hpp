#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream> // std::cout
#include <string>   // std::string
#include <cstdlib>  // std::strtol, std::tod
#include <cerrno>   // errno
#include <limits>   // std::numeric_limits
#include <cmath>    // std::isnan, std::isinf
#include <iomanip>  // std::setprecision

class ScalarConverter{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &nw);
    ScalarConverter&operator=(const ScalarConverter &nw);
    ~ScalarConverter();
  public:
    static void convert(std::string str);
};

#endif
