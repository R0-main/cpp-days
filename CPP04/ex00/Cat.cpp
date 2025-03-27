/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:49:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 09:59:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[CONSTRUCTOR] Cat" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "[COPY CONSTRUCTOR] Cat" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "[DESTRUCTOR] Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "[COPY ASIGNEMENT] Cat" << std::endl;
	this->type = other.type;
	return (*this);
}
