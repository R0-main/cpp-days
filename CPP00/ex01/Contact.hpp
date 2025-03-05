/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/04 10:40:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
  private:
	std::string darkest_secret;
	std::string phone_number;

	static std::string _truncate_string(std::string str);

  public:
	Contact(void);
	~Contact();

	void display(void) const;
	void display_inline(int index) const;
	static bool ask_property(std::string message, std::string *str,
		bool only_digits);

	void set_darkest_secret(std::string str);
	void set_phone_number(std::string str);

	void reset(void);

	std::string firstname;
	std::string lastname;
	std::string nickname;
};
