/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:11 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 14:55:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack(void) const;
};
