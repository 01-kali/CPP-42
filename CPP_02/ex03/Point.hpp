#ifndef POINT_HPP
#define POINT_HPP

#include <Fixed.hpp>

class Point
{
  private:
    const Fixed x; 
    const Fixed y; 
  public:
    Point();
    Point(const float x, const float y);
    Point(const Point &nw);
    Point &operator=(const Point &nw);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
    void printx() const;
    void printy() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
