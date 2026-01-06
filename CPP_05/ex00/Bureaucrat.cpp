#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(): name("default"), grade(100){}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name){
  this->grade = grade;
  if(grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if(grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &nw): name(nw.name), grade(nw.grade){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &nw){
  if(this != &nw)
    grade = nw.grade;
  return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(){
  return name;
}

int Bureaucrat::getGrade(){
  return grade;
}

void Bureaucrat::incrementGrade(){
  grade--;
  if(grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
  grade++;
  if(grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
  return ("Grade Too High.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
  return ("Grade Too Low.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a){
  return o << a.getName() << ", bureaucrat grade " << a.getGrade();
}
