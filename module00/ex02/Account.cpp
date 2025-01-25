#include "Account.hpp"

#include <iostream>

static int n_accounts = 0;

int Account::getNbAccounts(void) {
    return n_accounts;
}
int Account::getTotalAmount(void) {
    return 0;
}
int Account::getNbDeposits(void) {
    return 0;
}
int Account::getNbWithdrawals(void) {
    return 0;
}
void Account::displayAccountsInfos(void) {}

Account::Account(int initial_deposit)
    : _accountIndex(n_accounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    n_accounts++;
}
Account::~Account() {}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > this->_amount)
        return false;
    _amount -= withdrawal;
    _nbWithdrawals++;
    return true;
}
int Account::checkAmount(void) const {
    return 0;
}
void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
}

void Account::_displayTimestamp(void) {
    std::cout << "[0]";
}
