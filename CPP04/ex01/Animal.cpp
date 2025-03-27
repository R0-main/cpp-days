/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 11:08:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("")
{
	std::cout << "[CONSTRUCTOR] Animal" << std::endl;
	this->brain = new Brain();
}

Animal::Animal(const Animal &other)
{
	std::cout << "[COPY CONSTRUCTOR] Animal" << std::endl;
	this->brain = new Brain();
	*this = other;
}

Animal::~Animal()
{
	std::cout << "[DESTRUCTOR] Animal" << std::endl;
	if (this->brain)
		delete this->brain;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "[COPY ASIGNEMENT] Animal" << std::endl;
	this->type = other.type;
	this->brain = other.brain;
	return (*this);
}

Animal &Animal::operator=(const Animal *other)
{
	std::cout << "[COPY ASIGNEMENT] Animal" << std::endl;
	this->type = other->type;
	if (this->brain && other->brain)
		*this->brain = *other->brain;
	return (*this);
}

void Animal::makeSound(void) const
{

}

std::string Animal::getType(void) const
{
	return (this->type);
}
