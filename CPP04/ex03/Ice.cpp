/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:38:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice")
{

}

Ice::Ice(const Ice &other) : AMateria(other._type)
{
	*this = other;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &other)
{
	this->_type = other._type;
	return (*this);
}

Ice *Ice::clone() const
{
	Ice *ice = new Ice(*this);
	return (ice);
}

void use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
