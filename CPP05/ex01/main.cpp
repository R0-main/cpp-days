/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:00:06 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 08:52:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat emerik("Emerik", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat emerik("Emerik", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat emerik("Emerik", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat emerik("Emerik", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat emerik("Emerik", 1);

		std::cout << emerik << "\n";

		emerik.decrementGrade();

		std::cout << emerik << "\n";

		emerik.incrementGrade();
		std::cout << emerik << "\n";

		emerik.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat emerik("Emerik", 150);

		std::cout << emerik << "\n";
		emerik.incrementGrade();


		std::cout << emerik << "\n";

		emerik.decrementGrade();
		std::cout << emerik << "\n";

		emerik.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const Bureaucrat emerik("Emerik", 150);
		const Bureaucrat emerik2(emerik);

		std::cout << emerik << "\n";
		std::cout << emerik2 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		const Bureaucrat emerik("Emerik", 55);
		Form form("Civils Rights Act", 42, 42);

		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		const Bureaucrat emerik("Emerik", 42);
		Form form("Civils Rights Act", 42, 42);

		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

