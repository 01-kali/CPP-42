#include <Point.hpp>

Point::Point() : x(0), y(0)
{}

Point::Point(const float x, const float y) : x(x), y(y)
{}

Point::Point(const Point &nw) : x(nw.x), y(nw.y)
{}

Point &Point::operator=(const Point &nw)
{
  if(this != &nw)
  {
    x = nw.x;
    y = nw.y;
  }
  return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
  return(x);
}

Fixed Point::getY() const
{
  return(y);
}

void Point::printx() const
{
  std::cout << "x: " << x << std::endl; 
}
void Point::printy() const
{
  std::cout << "y: " << y << std::endl; 
}
