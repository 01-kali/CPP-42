#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <Intern.hpp>

int main(){
  {
    Intern i;
    AForm *a = i.makeForm("robotomy request", "Bender");
    if(a != NULL){
      Bureaucrat b("Bureaucrat", 1);
      b.signAForm(*a);
      try{
        a->execute(b);
      }
      catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
      }
      delete a;
    }
    std::cout << std::endl;
  }
  {
    Intern i;
    AForm *a = i.makeForm("presidential pardon", "Bender");
    if(a != NULL){
      Bureaucrat b("Bureaucrat", 1);
      b.signAForm(*a);
      try{
        a->execute(b);
      }
      catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
      }
      delete a;
    }
    std::cout << std::endl;
  }
  {
    Intern i;
    AForm *a = i.makeForm("shrubbery creation", "Bender");
    if(a != NULL){
      Bureaucrat b("Bureaucrat", 1);
      b.signAForm(*a);
      try{
        a->execute(b);
      }
      catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
      }
      delete a;
    }
    std::cout << std::endl;
  }
  {
    Intern i;
    AForm *a = i.makeForm("", "Bender");
    Bureaucrat b("Bureaucrat", 1);
    if(a != NULL){
      b.signAForm(*a);
      try{
        a->execute(b);
      }
      catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
      }
      delete a;
    }
  }
  return 0;
}
