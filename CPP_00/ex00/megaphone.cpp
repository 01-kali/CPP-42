#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (int i = 1; argv[i]; ++i)
  {
    char *arg = argv[i];
    for (int j = 0; arg[j]; ++j)
      std::cout << (char)std::toupper(arg[j]);
  }

  std::cout << std::endl;
  return 0;
}

