/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/25 14:27:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
  private:
	Contact _contacts[MAX_CONTACTS];

  public:
	PhoneBook();
	~PhoneBook();
};
