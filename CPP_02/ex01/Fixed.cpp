#include <Fixed.hpp>

Fixed::Fixed(): fixedPoint(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
  std::cout << "Int constructor called" << std::endl;
  fixedPoint = i << bits;
}

Fixed::Fixed(const float n)
{
  std::cout << "Float constructor called" << std::endl;
  fixedPoint = roundf(n * (1 << bits));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nw): fixedPoint(nw.fixedPoint)
{
  std::cout << "Copy constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixedPoint)
{
  out << fixedPoint.toFloat();
  return(out);
}

Fixed &Fixed::operator=(const Fixed &nw)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &nw)
    fixedPoint = nw.fixedPoint;
  return (*this);
}

int Fixed::getRawBits( void ) const
{
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
