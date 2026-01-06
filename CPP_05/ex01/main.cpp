#include <Bureaucrat.hpp>
#include <Form.hpp>

int main(){
  {
    try{
      Form a("A", 150, 170);
    }
    catch(std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    try{
      Form a("A", 0, 10);
    }
    catch(std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
  }
  {
    Form b("B", 2, 150);
    Bureaucrat d("D", 3);
    std::cout << b << std::endl;
    try{
      d.signForm(b);
    }
    catch(std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    Form a("A", 149, 50);
    std::cout << a << std::endl;
    std::cout << d << std::endl;
    d.signForm(a);
    std::cout << a << std::endl;
  }
  return 0;
}
