/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:51:00 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 09:30:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define URED "\e[4;31m"
# define RED "\e[0;31m"
# define MAG "\e[0;35m"
# define RESET "\e[0m"
# define BHMAG "\e[1;95m"
# define UMAG "\e[4;35m"
# define BLK "\e[0;30m"
# define BHRED "\e[1;91m"

class ScalarConverter
{
public:
	static void convert(const char *input);
};

