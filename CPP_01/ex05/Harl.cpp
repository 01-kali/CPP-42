#include <Harl.hpp>


void Harl::debug( void )
{
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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
    return;
  void (Harl::*functptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  (this->*functptr[i])();
}
