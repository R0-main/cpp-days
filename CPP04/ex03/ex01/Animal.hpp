/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:35:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:59:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"
#include <iostream>

class Animal
{
  protected:
	std::string type;
	Brain *brain;

  public:
	Animal(void);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	Animal &operator=(const Animal *other);

	virtual void makeSound(void) const;
	std::string getType(void) const;
};
