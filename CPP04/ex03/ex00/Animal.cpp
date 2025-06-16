/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:06:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("")
{
	std::cout << "[CONSTRUCTOR] Animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "[COPY CONSTRUCTOR] Animal" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "[DESTRUCTOR] Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "[COPY ASIGNEMENT] Animal" << std::endl;
	this->type = other.type;
	return (*this);
}

void Animal::makeSound(void) const
{

}

std::string Animal::getType(void) const
{
	return (this->type);
}
