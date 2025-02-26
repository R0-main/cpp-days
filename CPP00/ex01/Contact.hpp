/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/26 12:22:36 by rguigneb         ###   ########.fr       */
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
	~Contact(void);

	void display_inline(int index);
	void display(void);

	std::string firstname;
	std::string lastname;
	std::string nickname;
};
