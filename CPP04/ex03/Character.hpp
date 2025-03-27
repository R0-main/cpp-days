/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:27:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:33:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
  private:
	static const unsigned int _INVENTORY_SIZE = 4;

	std::string _name;
	AMateria	*_inventory[Character::_INVENTORY_SIZE];

  public:
	Character(std::string name);
	Character(const Character &other);
	virtual ~Character();
	Character &operator=(const Character &other);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
