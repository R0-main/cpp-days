/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:14 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/24 10:18:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
