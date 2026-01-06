#include <Harl.hpp>


void Harl::debug( void )
{
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
  std::cout << std::endl;
}

void Harl::info( void )
{
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
  std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
  std::cout << std::endl;
}

void Harl::warning( void )
{
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
  std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
  std::cout << std::endl;
}

void Harl::error( void )
{
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
  std::cout << std::endl;
}

int is_digit(std::string str)
{
  for (int i = -1; str.c_str()[++i];)
  {
    if (!std::isdigit(str.c_str()[i]))
      return 0;
  }
  return (1);
}

void Harl::complain( std::string level )
{
  int i;
  if (!is_digit(level) || (i = std::atoi(level.c_str())) < 0 || i > 3)
  {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
  }
  void (Harl::*functptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  (this->*functptr[i])();
}

string_code check_args(std::string level)
{
  if (level == "DEBUG") return debug; 
  if (level == "INFO") return info; 
  if (level == "WARNING") return warning; 
  if (level == "ERROR") return error;
  return autre;
}
