#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(): 
  AForm("PresidentialPardonForm", 25, 5), target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
  AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &nw): 
  AForm(nw), target(nw.target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &nw){
  if(this != &nw){
    AForm::operator=(nw);
    target = nw.target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::executeTheForm() const{
  std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

