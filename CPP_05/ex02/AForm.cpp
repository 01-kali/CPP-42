#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm(): name("default"), sign(false), sign_grade(100), exec_grade(100){
}

AForm::AForm(std::string name, int sign_grade, int exec_grade): 
  name(name), sign(false), sign_grade(sign_grade), exec_grade(exec_grade){
  if(sign_grade < 1 || exec_grade < 1)
    throw AForm::GradeTooHighException();
  else if(sign_grade > 150 || exec_grade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &nw): 
  name(nw.name), sign(nw.sign), sign_grade(nw.sign_grade), exec_grade(nw.exec_grade){}

AForm &AForm::operator=(const AForm &nw){
  if(this != &nw)
    sign = nw.sign;
  return *this;
}

AForm::~AForm(){
}

std::string AForm::getName() const{
  return name;
}

bool AForm::getSign(){
  return sign;
}

int AForm::getSignGrade(){
  return sign_grade;
}

int AForm::getExecGrade(){
  return exec_grade;
}

AForm::GradeTooHighException::GradeTooHighException(): std::runtime_error("Grade Too High."){}

AForm::GradeTooLowException::GradeTooLowException(): std::runtime_error("Grade Too Low."){}

AForm::NotSigned::NotSigned(): std::runtime_error("Not Signed."){}

void AForm::beSigned(Bureaucrat bc){
  if(bc.getGrade() > sign_grade)
    throw AForm::GradeTooLowException();
  sign = true;
}

void  AForm::execute(Bureaucrat const & executor) const{
  if(sign == false)
    throw AForm::NotSigned();
  if(executor.getGrade() > sign_grade)
    throw AForm::GradeTooLowException();
  executeTheForm();
}

std::ostream	&operator<<(std::ostream &o, AForm &form){
  return (o << form.getName() << ", sign: " << form.getSign() << ", sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade());
}
