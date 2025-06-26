/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:57:15 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/24 09:13:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <stdint.h>

int main(void)
{
	int d = 10;
	int *i = &d;

	uintptr_t ptr = Serialization::serialize<int>(i);

	std::cout << ptr << "\n";

	std::cout << Serialization::deserialize<int>(ptr) << "\n";
	std::cout << *Serialization::deserialize<int>(ptr) << "\n";
	return 0;
}

