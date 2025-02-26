/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 12:25:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
  private:
	Contact _contacts[MAX_CONTACTS];
	std::string _line;
	bool _stop;

	void process_line(void);

	void add_contact(void);
	void search_contact(void);
	std::string truncate_string(std::string str);

  public:
	PhoneBook();
	~PhoneBook();

	void loop(void);
	void show_contacts(void);
	void show_contact(int index);
};
