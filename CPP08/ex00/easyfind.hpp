/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 09:13:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
typename T::value_type easyfind(T t, int n)
{
	for (typename T::const_iterator i = t.begin(); i != t.end(); i++)
	{
		if (*i == n)
			return (*i);
	}
	throw std::exception();
}
