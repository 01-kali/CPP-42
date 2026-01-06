#ifndef FIXES_HPP
#define FIXES_HPP

#include <iostream>

class Fixed 
{
  private:
    int fixedPoint;
    static const int bits = 8;
  public:
    Fixed();
    Fixed(const Fixed &nw);
    Fixed &operator=(const Fixed &nw);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
