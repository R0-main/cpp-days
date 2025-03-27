/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:22:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:37:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
  protected:
	std::string _type;

  public:
	Cure(void);
	Cure(const Cure &materia);
	Cure &Cure::operator=(const Cure &other);
	~Cure();

	Cure *clone() const;
	void use(ICharacter &target);
};
