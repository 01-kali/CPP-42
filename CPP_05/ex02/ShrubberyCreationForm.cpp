#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(): 
  AForm("ShrubberyCreationForm", 145, 137), target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
  AForm("ShrubberyCreationForm" , 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &nw): 
  AForm(nw), target(nw.target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &nw){
  if(this != &nw){
    AForm::operator=(nw);
    target = nw.target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeTheForm() const{
  std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()){
      std::cout << target + "_shrubbery is open" << std::endl;
      return;
    }
    file << 
      "                                   # #### ####" << std::endl << 
      "                                 ### \\/#|### |/####" << std::endl << 
      "                                ##\\/#/ \\||/##/_/##/_#" << std::endl << 
      "                              ###  \\/###|/ \\/ # ###" << std::endl << 
      "                            ##_\\_#\\_\\## | #/###_/_####" << std::endl << 
      "                           ## #### # \\ #| /  #### ##/##" << std::endl << 
      "                            __#_--###`  |{,###---###-~" << std::endl << 
      "                                      \\ }{" << std::endl << 
      "                                       }}{" << std::endl << 
      "                                       }}{" << std::endl << 
      "                                       {{}" << std::endl << 
      "                                 , -=-~{ .-^- _" << std::endl << 
      "                                       `}" << std::endl << 
      "                                        {" << std::endl;
    file.close();
}
