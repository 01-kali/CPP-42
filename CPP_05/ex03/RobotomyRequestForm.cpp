#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(): 
  AForm("RobotomyRequestForm", 72, 45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
  AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &nw): 
  AForm(nw), target(nw.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &nw){
  if(this != &nw){
    AForm::operator=(nw);
    target = nw.target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeTheForm() const{
  std::cout << "drilling noises..." << std::endl;
  time_t now = time(0);
  if(now % 2 == 0){
    std::cout << target << " has been robotomized successfully." << std::endl;
    return ;
  }
  std::cout << "the robotomy failed." << std::endl;
}

