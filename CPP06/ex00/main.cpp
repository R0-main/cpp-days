/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:02:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/19 14:19:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char const *argv[])
{
	if (argc == 1 || argc > 2)
	{
		std::cerr << UMAG BHMAG "Usage" RESET BLK " > " RESET << argv[0] << " <:input>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

// int main(void)
// {
// 	ScalarConverter::convert("1");
// 	ScalarConverter::convert("1f");
// 	ScalarConverter::convert("1.f");
// 	ScalarConverter::convert("1.03f");
// 	ScalarConverter::convert("1.03");
// 	ScalarConverter::convert("1.0");
// 	ScalarConverter::convert("22");
// 	ScalarConverter::convert("22.f");
// 	return 0;
// }



