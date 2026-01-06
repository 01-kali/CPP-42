#include <Bureaucrat.hpp>
#include <AForm.hpp>

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
  if(this != &nw){
    grade = nw.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(){
  return name;
}

int Bureaucrat::getGrade() const{
  return grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::runtime_error("Grade Too High."){}

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::runtime_error("Grade Too Low."){}

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

void Bureaucrat::signAForm(AForm &f){
  try{
    f.beSigned(*this);
  }
  catch(std::runtime_error &e){
    std::cout << name << " couldn’t sign " << f.getName() << " because ";
    std::cout << e.what() << std::endl;
    return;
  }
  std::cout << name << " signed " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form){
  try{
    form.execute(*this);
  }
  catch(std::runtime_error &e){
    std::cout << name << " couldn’t execute " << form.getName() << " because "
      << e.what() << std::endl;
    return ;
  }
  std::cout << name << " executed " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a){
  return o << a.getName() << ", bureaucrat grade " << a.getGrade();
}
