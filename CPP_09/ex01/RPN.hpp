#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN{
  private:
    std::stack<int> data_;

  public:
    RPN();
    RPN(std::string polish_expression);
    RPN(const RPN &nw);
    RPN &operator=(const RPN &nw);
    ~RPN();

    int CheckOperators(const char &op);
    void GetVars(int &var1, int &var2);
};

#endif
