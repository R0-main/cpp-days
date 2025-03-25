/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:14 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 09:48:22 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  protected:
	void _say() const;
	void _say(std::string) const;

  public:
	ScavTrap(void);
	ScavTrap(std::string _name);
	ScavTrap &operator=(ScavTrap &other);
	~ScavTrap();

	void guardGate();
};
