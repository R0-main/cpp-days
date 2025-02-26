/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 12:23:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

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

void Contact::display_inline(int index)
{
	std::cout << std::right << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->firstname);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->lastname);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << Contact::truncate_string(this->nickname);
	std::cout << std::endl;
}

void Contact::display(void)
{
	std::cout << std::right << this->firstname << std::endl;
	std::cout << std::right << this->lastname << std::endl;
	std::cout << std::right << this->nickname << std::endl;
	std::cout << std::right << this->phone_number << std::endl;
	std::cout << std::right << this->darkest_secret << std::endl;
}
