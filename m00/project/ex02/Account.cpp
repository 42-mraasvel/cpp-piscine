#include <iostream>
#include "Account.hpp"

/*
Constructor
*/
Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0) {

	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << initial_deposit \
				<< ";created" << std::endl;

}

/*
Destructor

Decrement total accounts and amount
*/
Account::~Account(void) {

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";closed" << std::endl;

	Account::_totalAmount -= _amount;
	Account::_nbAccounts -= 1;
}


/* Methods */

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount \
				<< ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits += 1;

	std::cout	<< ";amount:" << _amount \
				<< ";nb_deposits:" << _nbDeposits \
				<< std::endl;

	// Set static variables
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount;
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals += 1;

		std::cout	<< ";withdrawal:" << withdrawal \
					<< ";amount:" << _amount \
					<< ";nb_withdrawals:" << _nbWithdrawals \
					<< std::endl;

		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		return true;
	} else {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals \
				<< std::endl;
}


/* Static functions and attributes */

/*
Time formatting

https://www.cplusplus.com/reference/ctime/strftime/
https://stackoverflow.com/questions/27934034/get-current-time-in-mm-dd-yyyy-in-c
*/
void Account::_displayTimestamp( void ) {
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[100];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	// Time formatting: YEAR MONTH DAY _ HOUR MINUTE SECOND
	strftime(buffer, 100, "[%Y%m%d_%H%M%S]", timeinfo);

	std::cout << buffer;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbDeposits;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts \
				<< ";total:" << _totalAmount \
				<< ";deposits:" << _totalNbDeposits \
				<< ";withdrawals:" << _totalNbWithdrawals \
				<< std::endl;
}

/* Initialize all static variables */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
