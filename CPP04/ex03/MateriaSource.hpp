/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:27:08 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:33:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
  private:
	static const unsigned int _MAX_MATERIAS = 4;
	AMateria *_materias[MateriaSource::_MAX_MATERIAS];

  public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};
