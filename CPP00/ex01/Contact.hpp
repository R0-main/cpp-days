/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/25 14:58:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact
{
  private:
	std::string darkest_secret;

  public:
	Contact(std::string firstname, std::string lastname, std::string nickname,
		std ::string darkest_secret);
	~Contact();

	std::string firstname;
	std::string lastname;
	std::string nickname;
};
