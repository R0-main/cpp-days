/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCatngCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:49:03 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 10:01:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "[CONSTRUCTOR] WrongCat" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "[COPY CONSTRUCTOR] WrongCat" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "[DESTRUCTOR] WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "[COPY ASIGNEMENT] WrongCat" << std::endl;
	this->type = other.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "[🐱] wouaf wouaf" << std::endl;
}
