/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:52 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 11:15:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Dog : public AAnimal
{
  public:
	Dog(void);
	Dog(const Dog &other);
	~Dog();
	Dog &operator=(const Dog &other);

	void makeSound(void) const;
};
