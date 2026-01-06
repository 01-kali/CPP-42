#include <Fixed.hpp>

//constructors, destructor
Fixed::Fixed(): fixedPoint(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
  std::cout << "Float constructor called" << std::endl;
  fixedPoint = roundf(n * (1 << bits));
}

Fixed::Fixed(const int i)
{
  std::cout << "Int constructor called" << std::endl;
  fixedPoint = i << bits;
}

Fixed::Fixed(const Fixed &nw): fixedPoint(nw.fixedPoint)
{
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

//member functions
int Fixed::getRawBits( void ) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return(fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
  fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
  return ((float)(fixedPoint) / (1 << bits));
}

int Fixed::toInt( void ) const
{
  return (fixedPoint) / (1 << bits);
}

Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
  if (val1 < val2)
    return val1;
  return val2;
}

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2)
{
  if (val1 < val2)
    return val1;
  return val2;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
  if (val1 > val2)
    return val1;
  return val2;
}

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2)
{
  if (val1 > val2)
    return val1;
  return val2;
}

//overload of the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixedPoint)
{
  out << fixedPoint.toFloat();
  return(out);
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &nw)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &nw)
    fixedPoint = nw.fixedPoint;
  return (*this);
}

//The 6 comparison operators: >, <, >=, <=, == and !=
bool Fixed::operator>(const Fixed &val2)const
{
  if(fixedPoint > val2.fixedPoint)
    return 1;
  return 0;
}

bool Fixed::operator<(const Fixed &val2)const
{
  if(fixedPoint < val2.fixedPoint)
    return 1;
  return 0;
}

bool Fixed::operator>=(const Fixed &val2)const
{
  if(fixedPoint >= val2.fixedPoint)
    return 1;
  return 0;
}

bool Fixed::operator<=(const Fixed &val2)const
{
  if(fixedPoint <= val2.fixedPoint)
    return 1;
  return 0;
}

bool Fixed::operator==(const Fixed &val2)const
{
  if(fixedPoint == val2.fixedPoint)
    return 1;
  return 0;
}

bool Fixed::operator!=(const Fixed &val2)const
{
  if(fixedPoint != val2.fixedPoint)
    return 1;
  return 0;
}

//The 8 arithmetic operators: +, -, *, /, a++, a--, ++a and --a.
Fixed &Fixed::operator+(const Fixed &val2)
{
  fixedPoint = (fixedPoint + val2.fixedPoint);
  return *this;
}

Fixed &Fixed::operator-(const Fixed &val2)
{
  fixedPoint = (fixedPoint - val2.fixedPoint);
  return *this;
}

Fixed &Fixed::operator*(const Fixed &val2)
{
  fixedPoint = (fixedPoint * val2.fixedPoint) / (1 << bits);
  return *this;
}

Fixed &Fixed::operator/(const Fixed &val2)
{
  fixedPoint = (fixedPoint << bits) / val2.fixedPoint;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed tmp = *this;
  fixedPoint++;
  return(tmp);
}

Fixed Fixed::operator--(int)
{
  Fixed tmp = *this;
  fixedPoint--;
  return(tmp);
}

Fixed &Fixed::operator++()
{
  fixedPoint++;
  return(*this);
}

Fixed &Fixed::operator--()
{
  fixedPoint--;
  return(*this);
}
