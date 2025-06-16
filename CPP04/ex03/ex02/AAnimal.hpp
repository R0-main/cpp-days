/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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

class AAnimal
{
  protected:
	std::string type;
	Brain *brain;

  public:
	AAnimal(void);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &other);
	AAnimal &operator=(const AAnimal *other);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};
