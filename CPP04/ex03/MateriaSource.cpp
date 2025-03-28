/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:53:51 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 08:55:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < MateriaSource::_MAX_MATERIAS; i++)
	{
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MateriaSource::_MAX_MATERIAS; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
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
	for (size_t i = 0; i < MateriaSource::_MAX_MATERIAS; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < MateriaSource::_MAX_MATERIAS; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (0);
}
