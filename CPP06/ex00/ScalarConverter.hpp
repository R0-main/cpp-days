/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:51:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/19 09:07:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarConverter
{
public:
	static void convert(const char *input);

	ScalarConverter();
	virtual ~ScalarConverter() = 0;
};

