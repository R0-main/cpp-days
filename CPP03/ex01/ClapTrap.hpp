/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:59 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/10 12:14:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
  private:
	bool _can_do_actions(void) const;

  protected:
	std::string _name;
	size_t _hit_points;
	size_t _energy_points;
	size_t _attack_damage;

	virtual void _say(void) const;
	virtual void _say(std::string str) const;

  public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	ClapTrap &operator=(ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
