/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:52 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:06:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat(void);
	Cat(const Cat &other);
	~Cat();
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
};
