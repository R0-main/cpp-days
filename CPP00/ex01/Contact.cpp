/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/27 08:44:24 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <strings.h>

#define NBLK "\x1B[0;30m"
#define NRED "\x1B[0;31m"
#define CREST "\x1B[0m"
#define BWHT "\x1B[1;37m"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

std::string Contact::truncate_string(std::string str)
{
	{
		if (str.length() > 10)
		{
			str = str.substr(0, 10);
			str[9] = '.';
		}
		return (str);
	}
}

void Contact::reset(void)
{
	this->firstname.erase();
	this->lastname.erase();
	this->nickname.erase();
	this->phone_number.erase();
	this->darkest_secret.erase();
}

void Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

void Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

bool Contact::ask_property(std::string message, std::string *str,
	bool only_digits)
{
	if (!str)
		return (false);
	std::cout << BWHT "	Enter the " << message << " : " CREST;
	std::getline(std::cin, *str);
	if (std::cin.fail() || (only_digits
			&& !(*str).find_first_not_of("0123456789")))
	{
		std::cerr << NRED "❌ Invalid input!" CREST;
		if (only_digits)
			std::cerr << NRED "(only digits are accepted for this field)" CREST;
		std::cout << std::endl;
		std::cin.clear();
		return (false);
	}
	if (str->empty())
	{
		std::cerr << NRED "❌ Field cannot be empty!" CREST << std::endl;
		return (false);
	}
	return (true);
}

void Contact::display_inline(int index) const
{
	if (this->firstname.empty())
		std::cout << NBLK;
	std::cout << std::right << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->firstname);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->lastname);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->nickname);
	std::cout << std::endl;
	std::cout << CREST;
}

void Contact::display(void) const
{
	if (this->firstname.empty())
	{
		std::cout << BWHT "No informations about this contact!" CREST << std::endl;
	}
	else
	{
		std::cout << std::right << BWHT "	ℹ️  First Name : " CREST << this->firstname << std::endl;
		std::cout << std::right << BWHT "	ℹ️  Last Name : " CREST << this->lastname << std::endl;
		std::cout << std::right << BWHT "	ℹ️  Nick Name : " CREST << this->nickname << std::endl;
		std::cout << std::right << BWHT "	📞 Phone Number : " CREST << this->phone_number << std::endl;
		std::cout << std::right << BWHT "	🤫 Darkest Secret : " CREST << this->darkest_secret << std::endl;
	}
}
