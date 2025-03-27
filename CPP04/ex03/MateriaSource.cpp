/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:53:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 13:02:47 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (size_t i = 0; i < MateriaSource::_MAX_MATERIAS; i++)
	{
		this->_materias[i] = other._materias[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
}
AMateria	*createMateria(std::string const &type);
