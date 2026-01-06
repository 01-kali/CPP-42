#include <Harl.hpp>

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    std::cout << "this program takes one parameter." << std::endl;
      return(1);
  }
  Harl hl;

  switch (check_args(argv[1]))
  {
    case debug:
      hl.complain("0");
      break;
    case info:
      hl.complain("1");
      break;
    case warning:
      hl.complain("2");
      break;
    case error:
      hl.complain("3");
      break;
    default:
      hl.complain("4");
      break;
  }
  return(0);
}
