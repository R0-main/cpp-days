/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 09:45:53 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &t1, T &t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template <typename T>
T min(T t1, T t2)
{
	if (t1 < t2)
		return t1;
	return t2;
}

template <typename T>
T max(T t1, T t2)
{
	if (t1 > t2)
		return t1;
	return t2;
}
