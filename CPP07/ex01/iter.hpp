/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 10:00:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T array[], size_t size, F function)
{
	for (size_t i = 0; i < size; i++)
	{
		function(reinterpret_cast<T&>(array[i]));
	}
}
