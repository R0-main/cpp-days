/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:29:39 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/16 14:58:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

#define EXIT_SUCCESS 0

int	main(void)
{
	PhoneBook book;

	book.loop();
	return (EXIT_SUCCESS);
}
