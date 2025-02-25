/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:29:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/25 14:10:32 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define EXIT_SUCCESS 0

int	main(int argc, char const **argv)
{
	std::string str;

	if (argc <= 1)
	{
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			str += argv[i];
		}
		for (size_t i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
	}
	std::cout << str << std::endl;
	return (EXIT_SUCCESS);
}
