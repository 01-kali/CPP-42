#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(){
  std::string line; 
  std::string key;
  std::string value_str;
  std::ifstream file("CPP_09/ex00/data.csv"); 
  size_t pos;

  if (!file.is_open())
    throw std::runtime_error("Error: could not open data.csv");
  std::getline(file, line);
  while (std::getline(file, line)){
    pos = line.find(",");

    key = line.substr(0, pos);
    value_str = line.substr(pos + 1);

    float float_value;
    std::stringstream ss(value_str);
    ss >> float_value;
    if (ss.fail())
      throw std::runtime_error("Error: Could not convert string to float.");
    data_[key] = float_value;
  }
  file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &nw): data_(nw.data_){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &nw){
  if(this != &nw)
    data_ = nw.data_;
  return *this;
}

BitcoinExchange::~BitcoinExchange(){}

bool IsLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return 1;
}

bool CheckDate(const std::string& date) {
  if (date.length() != 10) return false;
  if (date[4] != '-' || date[7] != '-') return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

  if (month == 2) {
    if (day > 29) return false;

    bool is_leap = IsLeapYear(year);
    if (day == 29 && !is_leap) return false;
  }

  return true;
}

static std::string trim(const std::string& str) {
  size_t first = str.find_first_not_of(" \t");
  if (std::string::npos == first) return str;
  size_t last = str.find_last_not_of(" \t");
  return str.substr(first, (last - first + 1));
}

void BitcoinExchange::BitcoinPrice(std::string data_base){
  std::string line;
  float value;
  std::string data_base_path = "CPP_09/ex00/" + data_base;
  std::ifstream file(data_base_path.c_str());

  if (!file.is_open())
    throw std::runtime_error("Error: database file doesn't exist.");

  std::getline(file, line);
  if(line != "date | value")
    throw std::runtime_error("Error: the first line should be \"date | value\".");

  while(std::getline(file, line)){
    if(line.empty()) continue;
      
      size_t pos = line.find("|");
      if(pos == std::string::npos){
        std::cout << "Error: bad input => " << line << std::endl;
        continue ;
      }

      std::string date = trim(line.substr(0, pos));
      std::string value_str = trim(line.substr(pos + 1));

      if(!CheckDate(date)){
        std::cout << "Error: bad input => " << line << std::endl;
        continue ;
      }

      std::stringstream ss(value_str);
      
      if (!(ss >> value)) {
        std::cout << "Error: Invalid format => " << line << std::endl;
        continue ;
      }

      if (value < 0) {
        std::cout << "Error: not a positive number => " << line << std::endl;
        continue ;
      }
      
      if (value > 1000) {
        std::cout << "Error: too large a number => " << line << std::endl;
        continue ;
      }

      std::map<std::string, float>::iterator it = data_.lower_bound(date);

      if (it == data_.begin() && it->first != date)
        std::cerr << "Error: date too old => " << date << std::endl;
      else {
        if (it == data_.end() || it->first != date)
          it--;
        std::cout << date << " => " << value << " = "<< std::fixed << std::setprecision(2) << (value * it->second) << std::endl;
      }
  }

  file.close();
}
