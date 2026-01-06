#include <ScalarConverter.hpp>

bool checkPseudo(std::string str){
  if(str == "-inff" || str == "+inff" || str == "nanf" 
      || str == "-inf" || str == "+inf" || str == "nan")
  {
    bool f = (str[str.size() - 2] == 'f' || str == "nanf");
    std::string dbl = str.substr(0, str.size() - f);
    std::string flt = dbl + "f";
    std::cout << "char: impossible" << std::endl 
      << "int: impossible" << std::endl 
      << "float: " << flt << std::endl 
      << "double: " << dbl << std::endl;
    return true;
  }
  return false;
}
void print(char c, int i, float f, double d){
  if (std::isnan(d) || std::isinf(d)){
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
  }
  else{
    if(d < std::numeric_limits<char>::min() 
        || d > std::numeric_limits<char>::max())
      std::cout << "char: impossible\n";
    else if(!isprint(c))
      std::cout << "char: Non displayable\n";
    else
      std::cout << "char: '" << c << "'" << std::endl;
    if(d < std::numeric_limits<int>::min() 
        || d > std::numeric_limits<int>::max())
      std::cout << "int: impossible\n";
    else
      std::cout << "int: " << i << std::endl;
  }
  std::cout << std::fixed << std::setprecision(1) 
    << "float: " << f << "f" << std::endl  
    << "double: " << d << std::endl;
}

void toChar(char c){
  std::cout << "char: '" << c  << "'"<< std::endl
    << "int: " << static_cast<int>(c) << std::endl 
    << std::fixed << std::setprecision(1)
    << "float: " << static_cast<float>(c) << "f" << std::endl 
    << "double: " << static_cast<double>(c) << std::endl;
}

int toInt(std::string str){
  char *end;
  errno = 0;
  long int val = std::strtol(str.c_str(), &end, 10);
  if(errno == 0 && *end == '\0' 
      && val >= std::numeric_limits<int>::min() 
      && val <= std::numeric_limits<int>::max()){
    int i = static_cast<int>(val);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    print(c,i,f,d);
    return true;
  }
  return false;
}

float toFloat(std::string str){
  char *end;
  errno = 0;
  if(str[str.size() - 1] != 'f' || str[str.size() - 2] == '.' || str[0] == '.') return false;
  str = str.substr(0, str.size() - 1);
  double val = std::strtod(str.c_str(), &end);
  if(errno == 0 && *end == '\0' 
      && val >= -std::numeric_limits<float>::max() 
      && val <= std::numeric_limits<float>::max()){
    float f = static_cast<float>(val);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);
    print(c,i,f,d);
    return true;
  }
  return false;
}

double toDouble(std::string str){
  char *end;
  errno = 0;
  if(str[str.size() - 1] == '.' || str[0] == '.'
       || str == "inf" || str == "+nan" || str == "-nan") return false;
  double val = std::strtod(str.c_str(), &end);
  if(errno == 0 && *end == '\0'){
    char c = static_cast<char>(val);
    int i = static_cast<int>(val);
    float f = static_cast<float>(val);
    print(c,i,f,val);
    return true;
  }
  return false;
}

void impossible(){
  std::cout << "char: impossible\n"
    << "int: impossible\n"
    << "float: impossible\n"
    << "double: impossible\n";
}

void ScalarConverter::convert(std::string str){
  if(checkPseudo(str)) return;
  if (str.size() == 1 && !isdigit(str[0]) && isprint(str[0])){
    toChar(str[0]);
    return ;
  }
  if(toInt(str)) return ;
  if(toFloat(str)) return ;
  if(toDouble(str)) return ;
  impossible();
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &nw){*this = nw;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &nw){
  (void)nw;
  return *this;
}

ScalarConverter::~ScalarConverter(){}
