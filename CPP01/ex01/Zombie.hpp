/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:26:11 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 14:06:04 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie();

	void setName(std::string name);
	void announce(void) const;
	std::string getName(void) const;
};

Zombie	*zombieHorde(int N, std::string name);
