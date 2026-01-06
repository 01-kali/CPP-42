#include <RPN.hpp>

RPN::RPN(){}

RPN::RPN(const RPN &nw):data_(nw.data_){}

RPN &RPN::operator=(const RPN &nw){
  if(this != &nw)
    data_ = nw.data_;
  return *this;
}

RPN::~RPN(){}

void RPN::GetVars(int &var1, int &var2){
  if(data_.size() < 2)
    throw std::runtime_error("Error: please enter a valid polish mathematical expression.");

  var1 = data_.top();
  data_.pop();
  
  var2 = data_.top();
  data_.pop();
}

int RPN::CheckOperators(const char &op){
  int var1;
  int var2;

  switch (op){
    case '-': return GetVars(var1, var2), var2 - var1;
    case '+': return GetVars(var1, var2), var2 + var1;
    case '*': return GetVars(var1, var2), var2 * var1;
    case '/':
      GetVars(var1, var2);

      if (var1 == 0) throw std::runtime_error("Error: division by zero.");

      return var2 / var1;
    default:
      throw std::runtime_error("Error: incorrecrt operator -> \"" + std::string(1, op) + "\"");
  }
}

RPN::RPN(std::string polish_expression){
  for (size_t i = 0; i < polish_expression.size(); i++){
    if(polish_expression[i] >= '0' && polish_expression[i] <= '9')
      data_.push(atoi(polish_expression.substr(i,1).c_str()));

    else if(polish_expression[i] != ' ')
      data_.push(CheckOperators(polish_expression.substr(i,1).c_str()[0]));
  }

  if(data_.size() == 1)
    std::cout << data_.top() << std::endl;

  else
    throw std::runtime_error("Error: please enter a valid polish mathematical expression.");
}
