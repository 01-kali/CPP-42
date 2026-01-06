#include <phonebook.hpp>

int main()
{
  std::string cmd;
  PhoneBook pb;

  std::cout << "ADD:save a new contact." << std::endl;
  std::cout << "SEARCH: display a specific contact." << std::endl;
  std::cout << "EXIT: The program quits and the contacts are lost forever." << std::endl;
  while(1)
  {
    std::cout << "pleas enter one of theas three commands (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, cmd);
    if(cmd == "ADD")
      pb.add();
    else if (cmd == "SEARCH")
      pb.search();
    else if(cmd == "EXIT" || std::cin.eof())
      break;
    else if(cmd != "")
      std::cout << "Invalid command: " << cmd << std::endl;
  }
  return (0);
}
