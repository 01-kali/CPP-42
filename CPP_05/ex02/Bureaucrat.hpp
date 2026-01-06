#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

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
    int getGrade() const;
    class GradeTooHighException: public std::runtime_error {
      public:
        GradeTooHighException();
    };
    class GradeTooLowException: public std::runtime_error{
      public:
        GradeTooLowException();
    };
    void incrementGrade();
    void decrementGrade();

    void signAForm(AForm &f);

    void executeForm(AForm const & form);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);

#endif
