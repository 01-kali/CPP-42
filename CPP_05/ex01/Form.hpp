#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form{
  private:
    const std::string name;
    bool sign;
    const int sign_grade;
    const int exec_grade;

  public:
    Form();
    Form(std::string name, int sign_grade, int exec_grade);
    Form(const Form &);
    Form &operator=(const Form &);
    ~Form();

    std::string getName();
    bool getSign();
    int getSignGrade();
    int getExecGrade();
    
    class GradeTooHighException: public std::runtime_error {
      public:
        GradeTooHighException();
    };
    class GradeTooLowException: public std::runtime_error{
      public:
        GradeTooLowException();
    };
    
    void beSigned(Bureaucrat bc);
};

std::ostream	&operator<<(std::ostream &o, Form &form);

#endif
