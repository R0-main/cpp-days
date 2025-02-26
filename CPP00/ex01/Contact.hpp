/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 15:47:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
  private:
	std::string darkest_secret;
	std::string phone_number;

	static std::string truncate_string(std::string str);

	public:
	Contact(void);
	~Contact();

	void display(void);
	void display_inline(int index);
	static bool ask_property(std::string message, std::string *str, bool only_digits);

	void set_darkest_secret(std::string str);
	void set_phone_number(std::string str);

	void reset(void);

	std::string firstname;
	std::string lastname;
	std::string nickname;
};
