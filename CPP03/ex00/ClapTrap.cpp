/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/10 11:33:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10),
	_energy_points(10), _attack_damage(0)
{
	this->_say("created!");
}

ClapTrap::~ClapTrap()
{
	this->_say("destroyed!");
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	*this = other;
	this->_say("copy constructor operator called!");
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	this->_hit_points = other._hit_points;
	this->_name = other._name;
	this->_say("copy asignement operator called!");
	return (*this);
}

bool ClapTrap::_can_do_actions(void) const
{
	return (this->_energy_points > 0 && this->_hit_points > 0);
}

void ClapTrap::_say() const
{
	std::cout << "ClapTrap " << this->_name << " ";
}

void ClapTrap::_say(std::string str) const
{
	std::cout << "ClapTrap " << this->_name << " " << str << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->_can_do_actions())
	{
		this->_say("could't attack anymore!");
		return ;
	}
	this->_say();
	std::cout << "attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
	// target.takeDamage(this->_attack_damage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
		return ;
	if (amount < this->_hit_points)
		this->_hit_points -= amount;
	else
		this->_hit_points = 0;
	this->_say();
	std::cout << "has taken " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_can_do_actions())
	{
		this->_say();
		std::cout << "could't repair anymore!" << std::endl;
		return ;
	}
	this->_hit_points += amount;
	this->_say();
	std::cout << "repaired " << amount << " points of hit points!" << std::endl;
}
