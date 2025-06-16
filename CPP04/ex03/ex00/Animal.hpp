/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:35:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 09:56:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal(void);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);

	virtual void makeSound(void) const;
	std::string getType(void) const;
};
