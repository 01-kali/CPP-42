#include <Fixed.hpp>

Fixed::Fixed(): fixedPoint(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nw): fixedPoint(nw.fixedPoint)
{
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &nw)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &nw)
  {
    fixedPoint = nw.fixedPoint;
  }
  return (*this);
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return(fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
  fixedPoint = raw;
}
