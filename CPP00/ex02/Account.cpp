/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:50:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 12:41:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <locale>

int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_nbAccounts = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(void)
{
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout <<
	"accounts:" << Account::_nbAccounts <<
	";total:" << Account::_totalAmount <<
	";deposits:" << Account::_totalNbDeposits <<
	";withdrawals:" << Account::_totalNbWithdrawals <<
	std::endl;
}

void Account::_displayTimestamp(void)
{
	std::tm *t;

    std::time_t result = std::time(NULL);
	t = std::localtime(&result);

    std::cout << "[" <<
	std::setfill('0') << std::setw(2) << t->tm_year - 100 + 2000 <<
	std::setfill('0') << std::setw(2) << t->tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << t->tm_mday <<
	"_" <<
	std::setfill('0') << std::setw(2) << t->tm_hour <<
	std::setfill('0') << std::setw(2) << t->tm_min <<
	std::setfill('0') << std::setw(2) << t->tm_sec <<
	"] ";

	// std::cout << "[19920104_091532] ";
}

void Account::makeDeposit(int deposit)
{
	this->checkAmount();
	if (deposit <= 0)
	{
		std::cout << ";deposit:refused";
	}
	else
	{
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;
		std::cout <<
		";deposit:" << deposit <<
		";amount:" << this->_amount <<
		";nb_deposits:" << this->_nbDeposits;
	}
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->checkAmount();
	if (withdrawal <= 0 || this->_amount <= withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;

		std::cout <<
		";withdrawal:" << withdrawal <<
		";amount:" << this->_amount <<
		";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	Account::_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex <<
	";p_amount:" << this->_amount;
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
	";amount:" << this->_amount <<
	";deposits:" << this->_nbDeposits <<
	";withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}
