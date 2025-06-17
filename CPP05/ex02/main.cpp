/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:00:06 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 11:07:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		const Bureaucrat emerik("Emerik", 42);

		std::string str("fwqfqfqffq");
		ShrubberyCreationForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";
		emerik.signForm(form);
		ShrubberyCreationForm form2(form);
		std::cout << form2 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const Bureaucrat emerik("Emerik", 150);

		std::string str("fwqfqfqffq");
		ShrubberyCreationForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";
		emerik.signForm(form);
		ShrubberyCreationForm form2(form);
		std::cout << form2 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const Bureaucrat emerik("Emerik", 1);

		std::string str("fwqfqfqffq");
		ShrubberyCreationForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.executeForm(form);
		emerik.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		const Bureaucrat emerik("Emerik", 1);

		std::string str("fwqfqfqffq");
		ShrubberyCreationForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.signForm(form);
		emerik.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		const Bureaucrat emerik("Emerik", 1);

		std::string str("fwqfqfqffq");
		RobotomyRequestForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.signForm(form);
		emerik.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		const Bureaucrat emerik("Emerik", 25);

		std::string str("fwqfqfqffq");
		PresidentialPardonForm form(str);
		std::cout << emerik << "\n";
		std::cout << form << "\n";

		emerik.signForm(form);
		emerik.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
