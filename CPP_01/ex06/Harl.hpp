#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <cstdlib>

enum string_code {
    debug,
    info,
    warning,
    error,
    autre,
};

class Harl
{
  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
  public:
    void complain( std::string level );
};

string_code check_args(std::string level);

#endif
