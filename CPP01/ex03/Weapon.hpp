/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:38 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/03 14:21:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string type);
	~Weapon();

	const std::string &getType() const;
	void setType(std::string new_type);
};
