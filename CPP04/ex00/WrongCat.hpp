/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:47:52 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/27 09:58:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);

	void makeSound(void) const;
};
