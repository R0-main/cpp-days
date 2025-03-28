/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:23:53 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 08:55:55 by rguigneb         ###   ########.fr       */
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
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character &Character::operator=(const Character &other)
{
	this->_name = other._name;
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (size_t i = 0; i < Character::_INVENTORY_SIZE; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m; // .clone() if we want to not delete the base material, however if we do ths we have to free it in the main
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return ;
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < (int)Character::_INVENTORY_SIZE && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
