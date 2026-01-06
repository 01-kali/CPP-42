#include <phonebook.hpp>

PhoneBook::PhoneBook() : i(0) {}

int is_digit(std::string str)
{
  for (int i = -1; str.c_str()[++i];)
  {
    if (!std::isdigit(str.c_str()[i]))
      return 0;
  }
  return (1);
}

void PhoneBook::clean()
{
  contacts[i].first_name = "";
  contacts[i].last_name = "";
  contacts[i].nickname = "";
  contacts[i].secret = "";
  contacts[i].p_number = "";
}

int PhoneBook::check_args()
{
  return (contacts[i].first_name.empty() || contacts[i].last_name.empty() || contacts[i].nickname.empty() || contacts[i].secret.empty() || contacts[i].p_number.empty() || !is_digit(contacts[i].p_number));
}

void PhoneBook::check()
{
  if (check_args())
  {
    clean();
    i--;
    std::cout << "Error: Contact not saved." << std::endl;
  }
}

void my_getline(std::string *str)
{

  std::getline(std::cin, *str);
  if(std::cin.eof())
    exit(0);
}
void PhoneBook::add()
{
  std::cout << "enter the first name: ";
  my_getline(&contacts[i].first_name);
  std::cout << "enter the last name: ";
  my_getline(&contacts[i].last_name);
  std::cout << "enter the nickname: ";
  my_getline(&contacts[i].nickname);
  std::cout << "enter the secret: ";
  my_getline(&contacts[i].secret);
  std::cout << "enter the phone number: ";
  my_getline(&contacts[i].p_number);
  check();
  if (++i >= 8)
    i = 0;
}

std::string format_field(std::string str)
{
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");
  return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::search()
{
  int x = -1;
  std::string number;
  std::cout << std::string(5, ' ') + "index" << "|"
    << "first name" << "|" << " last name" << "|"
    << "  nickname"<< std::endl;
  while(++x < 8)
  {
    std::cout << std::string(9, ' ') << x << "|"; 
    if (contacts[x].first_name != "")
    {
      std::cout << format_field(contacts[x].first_name) << "|"
      << format_field(contacts[x].last_name) << "|"
      << format_field(contacts[x].nickname) << std::endl;
    }
    else {
      std::cout << std::string(10, ' ') << "|"
      << std::string(10, ' ') << "|"
      << std::string(10, ' ') << std::endl;
    }
  }
  while(1)
  {
    std::cout << "Enter the index of the contact to display(0->7): ";
    std::getline(std::cin, number);
    if(std::cin.eof())
      exit(1);
    if(is_digit(number) && (x = std::atoi(number.c_str())) >= 0 && x <= 7)
        break;
  }
  std::cout << "First name : "<< contacts[x].first_name << std::endl;
  std::cout << "Last name : " << contacts[x].last_name << std::endl;
  std::cout << "Nickname : " << contacts[x].nickname << std::endl;
  std::cout << "Secret : " << contacts[x].secret << std::endl;
  std::cout << "Phone Number : " <<contacts[x].p_number << std::endl;
}
