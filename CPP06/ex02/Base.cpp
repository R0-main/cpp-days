/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:37:36 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 09:27:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return new B();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "it's a A class pointer!\n";
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "it's a B class pointer!\n";
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "it's a C class pointer!\n";
}

void	identify(Base &p)
{
	if (dynamic_cast<A *>(&p) != 0)
		std::cout << "it's a A class ref!\n";
	else if (dynamic_cast<B *>(&p) != 0)
		std::cout << "it's a B class ref!\n";
	else if (dynamic_cast<C *>(&p) != 0)
		std::cout << "it's a C class ref!\n";
}

A::A()
{
}

A::~A()
{
	std::cout << "A Class\n";
}

B::B()
{
}

B::~B()
{
	std::cout << "B Class\n";
}

C::C()
{
}

C::~C()
{
	std::cout << "C Class\n";
}
