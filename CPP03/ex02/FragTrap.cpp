/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:29 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 10:12:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_say("just been created! 💣");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	this->_say("just been created! 💣");
}

FragTrap::~FragTrap()
{
	this->_say("just been destroyed! 💣");
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	if (this != &other)
		this->ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::_say() const
{
	std::cout << "FragTrap " << this->_name << " ";
}

void FragTrap::_say(std::string str) const
{
	std::cout << "FragTrap " << this->_name << " " << str << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	this->_say("FragTrap high five someone!");
}

