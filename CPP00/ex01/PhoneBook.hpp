/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/27 08:52:56 by rguigneb         ###   ########.fr       */
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
	unsigned char _current_index;

	void _process_line(void);

	void _add_contact(void);
	void _search_contact(void);

  public:
	PhoneBook(void);
	~PhoneBook();

	void loop(void);
	void show_contacts(void) const;
	void show_contact(int index) const;
};
