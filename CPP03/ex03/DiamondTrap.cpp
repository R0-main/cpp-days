/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:29 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/24 10:24:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	this->_say("just been created!");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_say("just been created!");
}

DiamondTrap::~DiamondTrap()
{
	this->_say("just been destroyed!");
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	if (this != &other)
		this->ClapTrap::operator=(other);
	return (*this);
}

void DiamondTrap::_say() const
{
	std::cout << "DiamondTrap " << this->_name << " ";
}

void DiamondTrap::_say(std::string str) const
{
	std::cout << "DiamondTrap " << this->_name << " " << str << std::endl;
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap : " << this->_name << std::endl;
	std::cout << "ClapTrap : " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
