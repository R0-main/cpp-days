/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:31 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 15:04:22 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return (*this);
}

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	std::string format_str(name);

	for (size_t i = 0; i < format_str.length(); i++)
		format_str[i] = std::tolower(format_str[i]);
	if (format_str.find("request", 0) == std::string::npos)
		throw Intern::UnknownName();
	if (format_str.find("robotomy", 0) != std::string::npos)
		return new RobotomyRequestForm(target);
	else if (format_str.find("presidential", 0) != std::string::npos)
		return new PresidentialPardonForm(target);
	else if (format_str.find("shrubbery", 0) != std::string::npos)
		return new ShrubberyCreationForm(target);
	throw Intern::UnknownName();
}

Intern::UnknownName::UnknownName(void) throw()
{
}

const char *Intern::UnknownName::what(void) const throw()
{
	return ("Intern error: unknown form name provided.");
}
