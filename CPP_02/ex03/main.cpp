#include <Point.hpp>


int main()
{
  Point a(0.0f, 0.0f);
  Point b(4.0f, 0.0f);
  Point c(0.0f, 4.0f);
  Point pt(1.0f, 2.0f);



  if(bsp(a, b, c, pt))
    std::cout << "Point is inside the triangle" << std::endl;
  return 0;
}
