/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:49:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 09:58:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[CONSTRUCTOR] Dog" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "[COPY CONSTRUCTOR] Dog" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "[DESTRUCTOR] Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "[COPY ASIGNEMENT] Dog" << std::endl;
	this->type = other.type;
	return (*this);
}
