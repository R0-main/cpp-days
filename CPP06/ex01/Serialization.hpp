/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:20:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/24 09:11:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>

class Serialization
{
  public:
	Serialization();
	virtual ~Serialization() = 0;

	template <typename Data> static uintptr_t serialize(Data *ptr)
	{
		return (reinterpret_cast<uintptr_t>(ptr));
	}

	template <typename Data> static Data *deserialize(uintptr_t raw)
	{
		return (reinterpret_cast<Data *>(raw));
	}
};
