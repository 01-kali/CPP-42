#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat{
  private:
    const std::string name;
    int grade;
  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &nw);
    Bureaucrat &operator=(const Bureaucrat &nw);
    ~Bureaucrat();

    std::string getName();
    int getGrade();
    
    void incrementGrade();
    void decrementGrade();
    
    class GradeTooHighException: public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException: public std::exception{
      public:
        const char* what() const throw();
    };
    
    void signForm(Form &f);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);

#endif
