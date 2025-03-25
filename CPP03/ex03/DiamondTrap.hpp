/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:14 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 09:51:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
  private:
	std::string _name;

  protected:
	void _say() const;
	void _say(std::string) const;

  public:
	DiamondTrap(void);
	DiamondTrap(std::string _name);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap &other);

	void attack(const std::string &target);
	void whoAmI(void) const;
};
