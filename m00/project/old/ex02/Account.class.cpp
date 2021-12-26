#include <iostream>
#include "Account.class.hpp"

/*
Out:
`[19920104_091532] index:0;amount:42;created`
`[20210615_212521] index:0;amount:42;created`
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
Out:
`[19920104_091532] index:0;amount:47;closed`
`[20210615_212521] index:0;amount:47;closed`
*/
Account::~Account(void) {

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";closed" << std::endl;

	Account::_totalAmount -= _amount;
	Account::_nbAccounts -= 1;
}

/*
Out:
`[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1`
`[20210615_213140] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1`
*/
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

/*
Out:
`[19920104_091532] index:0;p_amount:47;withdrawal:refused`
`[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1`

`[20210615_213620] index:0;p_amount:47;withdrawal:refused`
`[20210615_213620] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1`
*/
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

/*
https://www.geeksforgeeks.org/c-mutable-keyword/

Declare mutable int _checkAmountCount; inside of Account class for bonus-bonus
This keyword allows the variable to be modified despite being part of a const instance
*/
int		Account::checkAmount( void ) const {
	// _checkAmountCount++;
	return _amount;
}

/*
Out:
`[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0`
`[20210615_212910] index:0;amount:42;deposits:0;withdrawals:0`
*/
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
https://www.cplusplus.com/reference/ctime/strftime/
https://stackoverflow.com/questions/27934034/get-current-time-in-mm-dd-yyyy-in-c
*/
void Account::_displayTimestamp( void ) {
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[100];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	// Time formatting:
	// YYYYMMDD_HHMMSS
	// YEAR MONTH DAY _ HOUR MINUTE SECOND
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

/*
Out:
`[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0`
`[20210615_212521] accounts:8;total:20049;deposits:0;withdrawals:0`
*/
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
