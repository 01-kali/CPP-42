#ifndef FIXES_HPP
#define FIXES_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
  private:
    int fixedPoint;
    static const int bits = 8;
  public:
    Fixed();
    Fixed(const int i);
    Fixed(const float n);
    Fixed(const Fixed &nw);
    Fixed &operator=(const Fixed &nw);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedPoint);

#endif
