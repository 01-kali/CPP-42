#ifndef INTERN_HPP
#define INTERN_HPP

#include <AForm.hpp>

class Intern{
  public:
    Intern();
    Intern(const Intern &nw);
    Intern &operator=(const Intern &nw);
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);
};

#endif
