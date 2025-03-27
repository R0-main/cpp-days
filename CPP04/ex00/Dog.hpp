/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:52 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:06:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog(void);
	Dog(const Dog &other);
	~Dog();
	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};
