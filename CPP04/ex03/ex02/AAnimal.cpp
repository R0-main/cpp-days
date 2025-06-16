/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:38:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 11:11:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("")
{
	std::cout << "[CONSTRUCTOR] AAnimal" << std::endl;
	this->brain = new Brain();
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "[COPY CONSTRUCTOR] AAnimal" << std::endl;
	this->brain = new Brain();
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "[DESTRUCTOR] AAnimal" << std::endl;
	if (this->brain)
		delete this->brain;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "[COPY ASIGNEMENT] AAnimal" << std::endl;
	this->type = other.type;
	this->brain = other.brain;
	return (*this);
}

AAnimal &AAnimal::operator=(const AAnimal *other)
{
	std::cout << "[COPY ASIGNEMENT] AAnimal" << std::endl;
	this->type = other->type;
	if (this->brain && other->brain)
		*this->brain = *other->brain;
	return (*this);
}

void AAnimal::makeSound(void) const
{

}

std::string AAnimal::getType(void) const
{
	return (this->type);
}
