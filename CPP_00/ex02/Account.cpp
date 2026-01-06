#include <Account.hpp>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
  return (_nbAccounts);
}

int	Account::getTotalAmount()
{
  return(_totalAmount);
}

int	Account::getNbDeposits()
{
  return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
  return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
  time_t now = time(0);
  struct tm datetime = *localtime(&now);
  char output[20];

  strftime(output, 19, "[%Y%m%d_%H%M%S] ", &datetime);
  std::cout << output;
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit):
  _accountIndex(_nbAccounts),
  _nbDeposits(0), _nbWithdrawals(0)
{
  _amount = initial_deposit;
    _displayTimestamp();
  std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";created" << std::endl
    ;
  _nbAccounts++;
  _totalAmount = _totalAmount + _amount;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos()
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts()
    << ";total:" << _totalAmount
    << ";deposits:" << Account::getNbDeposits()
    << ";withdrawals:" << Account::getNbWithdrawals()
    << std::endl;
  _totalAmount = 0;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus() const
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  _nbDeposits++;
  _totalNbDeposits++;
  _amount = _amount + deposit;
  std::cout << ";deposit:" << deposit << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits << std::endl;
  _totalAmount = _totalAmount + _amount;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal( int withdrawal )
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  if(withdrawal > _amount)
    std::cout << ";withdrawal:refused" << std::endl;
  else {
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount = _amount - withdrawal;
    std::cout << ";withdrawal:" << withdrawal
      << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals
      << std::endl;
  }
  _totalAmount = _totalAmount + _amount;
  return(_nbWithdrawals);
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account()
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";closed" << std::endl
;
}
