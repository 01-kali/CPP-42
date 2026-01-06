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
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    
    static Fixed &min(Fixed &val1, Fixed &val2);
    const  static Fixed &min(const Fixed &val1, const Fixed &val2);
    static Fixed &max(Fixed &val1, Fixed &val2);
    const  static Fixed &max(const Fixed &val1, const Fixed &val2);
    
    Fixed &operator=(const Fixed &nw);
    
    bool operator>(const Fixed &val2)const;
    bool operator<(const Fixed &val2)const;
    bool operator>=(const Fixed &val2)const;
    bool operator<=(const Fixed &val2)const;
    bool operator==(const Fixed &val2)const;
    bool operator!=(const Fixed &val2)const;
    
    Fixed &operator+(const Fixed &val2);
    Fixed &operator-(const Fixed &val2);
    Fixed &operator*(const Fixed &val2);
    Fixed &operator/(const Fixed &val2);
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator++();
    Fixed &operator--();
    
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedPoint);

#endif
