#include <Point.hpp>

float sign (const Point p1, const Point p2, const Point p3)
{
  Fixed a = p1.getX() - p3.getX();
  Fixed b = p2.getY() - p3.getY();
  Fixed c = p2.getX() - p3.getX();
  Fixed d = p1.getY() - p3.getY();


  Fixed e = a * b;
  Fixed f = c * d;
  Fixed z = e - f;
  return (z.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
  float d1, d2, d3;
  bool neg, pos;

  d1 = sign(point, a, b);
  d2 = sign(point, b, c);
  d3 = sign(point, c, a);
  
  if (d1 == 0 || d2 == 0 || d3 == 0)
    return 0;
  neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
  return !(neg && pos);
}
