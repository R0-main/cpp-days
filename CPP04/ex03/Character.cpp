/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:23:53 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:34:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{

}

Character::Character(const Character &other)
{
	*this = other;
}

Character::~Character()
{
}

Character &Character::operator=(const Character &other)
{
	this->_name = other._name;
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = other._inventory[i];
	}
	return (*this);
}
