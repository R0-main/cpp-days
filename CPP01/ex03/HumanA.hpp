/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:11 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 14:27:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void attack(void) const;
};
