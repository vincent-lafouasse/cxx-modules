#include "Account.hpp"

#include <ctime>
#include <iostream>

static int n_accounts = 0;
static int total_amount = 0;
static int n_deposits = 0;
static int n_withdrawals = 0;

int Account::getNbAccounts(void) {
    return n_accounts;
}
int Account::getTotalAmount(void) {
    return total_amount;
}
int Account::getNbDeposits(void) {
    return n_deposits;
}
int Account::getNbWithdrawals(void) {
    return n_withdrawals;
}
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << n_accounts << ";";
    std::cout << "total:" << total_amount << ";";
    std::cout << "deposits:" << n_deposits << ";";
    std::cout << "withdrawals:" << n_withdrawals;
    std::cout << "\n";
}

Account::Account(int initial_deposit)
    : _accountIndex(n_accounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    n_accounts++;
    total_amount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created\n";
}
Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed\n";
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    _nbDeposits++;
    total_amount += deposit;
    n_deposits++;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}
bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    if (withdrawal > this->_amount) {
        std::cout << "withdrawal:refused\n";
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    total_amount -= withdrawal;
    n_withdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}
int Account::checkAmount(void) const {
    return 0;
}
void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << "\n";
}

static bool is_debug_mode() {
    const char* is_debug = std::getenv("DEBUG");
    return is_debug;
}

void Account::_displayTimestamp(void) {
    if (is_debug_mode()) {
        std::cout << "[19920104_091532] ";
        return;
    }

    std::time_t now = std::time(nullptr);
    std::tm* now_gmt = std::gmtime(&now);

    std::cout << "[";
    std::cout << now_gmt->tm_year;
    std::cout << now_gmt->tm_mon;
    std::cout << now_gmt->tm_mday;
    std::cout << "_";
    std::cout << now_gmt->tm_hour;
    std::cout << now_gmt->tm_min;
    std::cout << now_gmt->tm_sec;
    std::cout << "] ";
}
