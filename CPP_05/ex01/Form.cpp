#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form(): name("default"), sign(false), sign_grade(100), exec_grade(100){
}

Form::Form(std::string name, int sign_grade, int exec_grade): 
  name(name), sign(false), sign_grade(sign_grade), exec_grade(exec_grade){
  if(sign_grade < 1 || exec_grade < 1)
    throw Form::GradeTooHighException();
  else if(sign_grade > 150 || exec_grade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &nw): 
  name(nw.name), sign(nw.sign), sign_grade(nw.sign_grade), exec_grade(nw.exec_grade){}

Form &Form::operator=(const Form &nw){
  if(this != &nw)
    sign = nw.sign;
  return *this;
}

Form::~Form(){
}

std::string Form::getName(){
  return name;
}

bool Form::getSign(){
  return sign;
}

int Form::getSignGrade(){
  return sign_grade;
}

int Form::getExecGrade(){
  return exec_grade;
}

Form::GradeTooHighException::GradeTooHighException(): std::runtime_error("Grade Too High."){}

Form::GradeTooLowException::GradeTooLowException(): std::runtime_error("Grade Too Low."){}

void Form::beSigned(Bureaucrat bc){
  if(bc.getGrade() > sign_grade)
    throw Form::GradeTooLowException();
  sign = true;
}

std::ostream	&operator<<(std::ostream &o, Form &form){
  return (o << form.getName() << ", sign: " << form.getSign() << ", sign_grade: " << form.getSignGrade() << ", exec_grade: " << form.getExecGrade());
}
