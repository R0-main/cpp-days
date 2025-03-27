/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimalnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:00:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("")
{
	std::cout << "[CONSTRUCTOR] WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "[COPY CONSTRUCTOR] WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[DESTRUCTOR] WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "[COPY ASIGNEMENT] WrongAnimal" << std::endl;
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	if (this->type == "Cat")
		std::cout << "[🐶] wouaf wouaf" << std::endl;
	else if (this->type == "Dog")
		std::cout << "[🐱] miaou" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
