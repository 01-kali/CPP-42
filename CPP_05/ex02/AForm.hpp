#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

class Bureaucrat;

class AForm{
  private:
    const std::string name;
    bool sign;
    const int sign_grade;
    const int exec_grade;

  public:
    AForm();
    AForm(std::string name, int sign_grade, int exec_grade);
    AForm(const AForm &);
    AForm &operator=(const AForm &);
    virtual ~AForm();

    std::string getName() const;
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
    class NotSigned: public std::runtime_error{
      public:
        NotSigned();
    };
    void beSigned(Bureaucrat bc);

    void  execute(Bureaucrat const & executor) const;
    virtual void executeTheForm() const = 0;

};

std::ostream	&operator<<(std::ostream &o, AForm &form);

#endif
