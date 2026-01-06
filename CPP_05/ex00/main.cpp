#include <Bureaucrat.hpp>

int main()
{
  {
    try{
      Bureaucrat a("test", 160);
    }
    catch(const std::exception &e){
      std::cout << e.what() << std::endl;
    }
    try{
      Bureaucrat a("test", 0);
    }
    catch(const std::exception &e){
      std::cout << e.what() << std::endl;
    }
    try{
      Bureaucrat a("test", 10);
      std::cout << a << std::endl;
    }
    catch(const std::exception &e){
      std::cout << e.what() << std::endl;
    }
  }
  {
    Bureaucrat c("Bureaucrat1",148);
    Bureaucrat b("Bureaucrat2",2);
    Bureaucrat a(c);
    for (int i = 0; i <= 151; i++){
      try{
        std::cout << a << std::endl;
        a.decrementGrade();
      }
      catch(std::exception &e){
        std::cout << e.what() << std::endl;
        break;
      }
    }
    a = b;
    try{
      for(int i = 10; i >= 0; i--){
        std::cout << a << std::endl;
        a.incrementGrade();
      }
    }
    catch(std::exception &e){
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}
