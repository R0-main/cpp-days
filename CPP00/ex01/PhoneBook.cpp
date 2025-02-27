/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:33 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 15:56:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

#define NRED "\x1B[0;31m"
#define CREST "\x1B[0m"

#define RESET_RETURN(contact) { contact.reset(); return; }

PhoneBook::PhoneBook()
{
	this->_stop = false;
	this->_current_index = 0;
	std::cout << "Available Commands : ADD, SEARCH, EXIT" << std::endl;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(void)
{
	std::string tmp;
	if (this->_current_index >= MAX_CONTACTS)
		this->_current_index = 0;
	Contact &contact = this->_contacts[this->_current_index];
	if (!Contact::ask_property("firstname", &contact.firstname, false))
		RESET_RETURN(contact)
	if (!Contact::ask_property("lastname", &contact.lastname, false))
		RESET_RETURN(contact)
	if (!Contact::ask_property("nickname", &contact.nickname, false))
		RESET_RETURN(contact)
	if (!Contact::ask_property("phone_number", &tmp, true))
		RESET_RETURN(contact)
	contact.set_phone_number(tmp);
	if (!Contact::ask_property("darkest_secret", &tmp, false))
		RESET_RETURN(contact)
	contact.set_darkest_secret(tmp);
	this->_current_index++;
}

void PhoneBook::search_contact(void)
{
	int	index;

	this->show_contacts();
	std::cout << "Index > ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cerr << NRED "❌ Invalid input!" CREST << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		std::cerr << NRED "Please provide a valid index" CREST << std::endl;
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
	else if (this->_line == "SEARCH")
		this->search_contact();
	else if (this->_line == "EXIT")
		this->_stop = true;
}

void PhoneBook::loop(void)
{
	while (!this->_stop)
	{
		std::cout << "> ";
		std::getline(std::cin, this->_line);
		if (std::cin.eof())
			break ;
		this->process_line();
	}
}
