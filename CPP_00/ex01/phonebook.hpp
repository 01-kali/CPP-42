#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>    //std::cout/cin
#include <string>      // std::string
#include <cctype>      // std::isdigit
#include <cstdlib>     // std::exit/atoi
#include <Contact.hpp>

class PhoneBook
{
  private:
    int i;
    Contact contacts[8];
  public:
    PhoneBook();
    void clean();
    int check_args();
    void check();
    void add();
    void search();
};

int is_digit(std::string number);

#endif
