/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:34:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/05 11:27:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	if (this->_level.compare("DEBUG") == 0)
		std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	if (this->_level.compare("INFO") == 0)
		std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	if (this->_level.compare("WARNING") == 0)
		std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	if (this->_level.compare("ERROR") == 0)
		std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	this->_level = level;
	switch (this->_filter)
	{
		case Harl::ALL:
			std::cout << "ALL" << std::endl;
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

void Harl::setFilterType(Harl::E_Types type)
{
	this->_filter = type;
}

Harl::Harl(void)
{
	this->_filter = Harl::ALL;
}

Harl::~Harl()
{
}
