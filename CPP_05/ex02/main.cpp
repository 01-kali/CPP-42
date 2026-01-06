#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main(){
  {
    Bureaucrat b("Bureaucrat", 1);
    AForm *a = new ShrubberyCreationForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
    a = new RobotomyRequestForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
    a = new PresidentialPardonForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
  }
  {
    std::cout << std::endl;
    Bureaucrat b("Bureaucrat", 150);
    AForm *a = new ShrubberyCreationForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
    a = new RobotomyRequestForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
    a = new PresidentialPardonForm();
    b.signAForm(*a);
    try{
      a->execute(b);
    }
    catch (std::runtime_error &e){
      std::cout << e.what() << std::endl;
    }
    delete a;
  }
  return 0;
}
