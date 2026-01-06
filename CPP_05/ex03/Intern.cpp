#include <Intern.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern(){}

Intern::Intern(const Intern &nw){
  (void)nw;
}

Intern &Intern::operator=(const Intern &nw){
  (void)nw;
  return *this;
}

Intern::~Intern(){}

AForm	*robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target){
  AForm	*(*fct[3])(std::string target) = {robotomy, presidential, shrubbery};
  std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
  AForm	*tmp = NULL;
  int i = -1;
  while(++i < 3 && formName != msg[i]){}
  if(i < 3){
      tmp = fct[i](target);
      std::cout << "Intern creates " << *tmp << std::endl;
      return tmp;
  }
  std::cout << "Unknown Form exception." << std::endl;
  return 0;
}
