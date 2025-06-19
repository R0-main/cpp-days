/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:02:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/19 09:50:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	(void)argc; (void)argv;
	if (argc == 1 || argc > 2)
	{
		std::cerr << "Invalid Args" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

