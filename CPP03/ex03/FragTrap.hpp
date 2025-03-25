/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:34:14 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/25 09:48:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  protected:
	void _say() const;
	void _say(std::string) const;

  public:
	FragTrap(void);
	FragTrap(std::string _name);
	~FragTrap();
	FragTrap &operator=(FragTrap &other);

	void highFivesGuys();
};
