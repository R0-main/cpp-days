/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 09:59:14 by rguigneb         ###   ########.fr       */
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
	if (this->type == "Dog")
		std::cout << "[🐶] wouaf wouaf" << std::endl;
	else if (this->type == "Cat")
		std::cout << "[🐱] miaou" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
