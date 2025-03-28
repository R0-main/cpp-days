/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:29 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 10:14:52 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_say("just been created!");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_say("just been created!");
}

ScavTrap::~ScavTrap()
{
	this->_say("just been destroyed!");
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	if (this != &other)
		this->ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::_say() const
{
	std::cout << "ScavTrap " << this->_name << " ";
}

void ScavTrap::_say(std::string str) const
{
	std::cout << "ScavTrap " << this->_name << " " << str << std::endl;
}

void ScavTrap::guardGate(void)
{
	this->_say("is now in Gate keeper mode");
}
