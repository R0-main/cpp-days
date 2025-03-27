/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:22:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 12:37:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

class Ice : public AMateria
{
  protected:
	std::string _type;

  public:
	Ice(void);
	Ice(const Ice &materia);
	Ice &operator=(const Ice &other);
	~Ice();

	Ice *clone() const;
	void use(ICharacter &target);
};
