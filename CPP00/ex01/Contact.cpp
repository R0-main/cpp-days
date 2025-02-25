/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/25 14:58:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstname, std::string lastname,
	std::string nickname, std::string darkest_secret) : firstname(firstname),
	lastname(lastname), nickname(nickname), darkest_secret(darkest_secret)
{
}

Contact::~Contact()
{
}
