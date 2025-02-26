/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 12:28:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
	this->_stop = false;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(void)
{
	this->_contacts[0].firstname = "0123456789";
}

void PhoneBook::search_contact(void)
{
	int	index;

	this->show_contacts();
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "Invalid input!" << std::endl;
		return ;
	}
	this->show_contact(index);
}

void PhoneBook::show_contacts(void)
{
	for (size_t i = 0; i < MAX_CONTACTS; i++)
	{
		this->_contacts[i].display_inline(i);
	}
}

void PhoneBook::show_contact(int index)
{
	if (index < 0 || index >= MAX_CONTACTS)
	{
		std::cerr << "Please provide a valid index" << std::endl;
		return ;
	}
	this->_contacts[index].display();
}

void PhoneBook::process_line(void)
{
	if (this->_line.empty())
		return ;
	if (this->_line == "ADD")
		this->add_contact();
	if (this->_line == "SEARCH")
		this->search_contact();
	if (this->_line == "EXIT")
		this->_stop = true;
}

void PhoneBook::loop(void)
{
	while (!this->_stop)
	{
		std::getline(std::cin, this->_line);
		if (std::cin.eof())
			break ;
		this->process_line();
	}
}
