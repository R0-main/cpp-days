/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:35:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 08:40:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
