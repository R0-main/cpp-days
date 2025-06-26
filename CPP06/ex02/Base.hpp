/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:03:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/26 09:09:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>

class Base
{
  public:
	virtual ~Base() = 0;
};

class A : public Base
{
  public:
	A();
	~A();
};

class B : public Base
{
  public:
	B();
	~B();
};

class C : public Base
{
  public:
	C();
	~C();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
