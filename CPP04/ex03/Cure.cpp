/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:38:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{

}

Cure::Cure(const Cure &other) : AMateria(other._type)
{
	*this = other;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &other)
{
	this->_type = other._type;
	return (*this);
}

Cure *Cure::clone() const
{
	Cure *cure = new Cure(*this);
	return (cure);
}

void use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
