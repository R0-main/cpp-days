/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 12:36:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

void Harl::debug(void)
{
	if (this->_level.compare("DEBUG") != 0)
		return ;
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." <<
	"I really do!" <<
	std::endl << std::endl;;
}

void Harl::info(void)
{
	if (this->_level.compare("INFO") != 0)
		return;
	std::cout << "[ INFO ]" << std::endl;
	std::cout <<
	"I cannot believe adding extra bacon costs more money." <<
	"You didn’t put enough bacon in my burger!" <<
	std::endl <<
	"If you did, I wouldn’t be asking for more!" <<
	std::endl << std::endl;
}

void Harl::warning(void)
{
	if (this->_level.compare("WARNING") != 0)
		return;
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<
	"I think I deserve to have some extra bacon for free." <<
	std::endl <<
	"I’ve been coming for years whereas you started working here since last month." <<
	std::endl << std::endl;
}

void Harl::error(void)
{
	if (this->_level.compare("ERROR") != 0)
		return;
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl  << std::endl;;
}

void Harl::complain(std::string level)
{
	this->_level = level;
	switch (this->_filter)
	{
		case Harl::UNDIFINED:
		case Harl::NONE:
			break;
		case Harl::ALL:
		case Harl::DEBUG:
			this->debug();
		case Harl::INFO:
			this->info();
		case Harl::WARNING:
			this->warning();
		case Harl::ERROR:
			this->error();
		break;
	}
}

Harl::E_Types Harl::getFilterType(void) const
{
	return (this->_filter);
}

void Harl::setFilterType(char *str)
{
	if (std::string("NONE").compare(str) == 0)
		this->_filter = Harl::NONE;
	else if (std::string("ALL").compare(str) == 0)
		this->_filter = Harl::ALL;
	else if (std::string("DEBUG").compare(str) == 0)
		this->_filter = Harl::DEBUG;
	else if (std::string("INFO").compare(str) == 0)
		this->_filter = Harl::INFO;
	else if (std::string("WARNING").compare(str) == 0)
		this->_filter = Harl::WARNING;
	else if (std::string("ERROR").compare(str) == 0)
		this->_filter = Harl::ERROR;
	else
		this->_filter = Harl::UNDIFINED;
}

Harl::Harl(void)
{
	this->_filter = Harl::ALL;
}

Harl::~Harl()
{
}
