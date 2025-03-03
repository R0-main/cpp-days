/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:12:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 14:21:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	const std::string &type_ref = this->type;
	return (type_ref);
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
