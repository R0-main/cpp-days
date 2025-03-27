/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:23:53 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 13:39:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	*this = other;
}

Character::~Character()
{
	// for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	// {
	// 	if (this->_inventory[i])
	// 		delete this->_inventory[i];
	// }
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

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
