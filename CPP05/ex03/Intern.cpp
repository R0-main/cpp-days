/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:31 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/24 09:02:50 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::t_mapping Intern::mapping[Intern::__E_FORMS_COUNT__] = {
	(Intern::t_mapping){
		.words = {"robotomy", "request"},
		.id = Intern::E_RobotomyRequestForm
	},
	(Intern::t_mapping){
		.words = {"presidential", "pardon"},
		.id = Intern::E_PresidentialPardonForm
	},
	(Intern::t_mapping){
		.words = {"shrubbery", "creation"},
		.id = Intern::E_ShrubberyCreationForm
	}
};

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
	Intern::t_e_forms form_id = __E_FORMS_NONE__;

	for (size_t i = 0; i < format_str.length(); i++)
		format_str[i] = std::tolower(format_str[i]);

	for (size_t i = 0; i < Intern::__E_FORMS_COUNT__; i++)
	{
		for (size_t z = 0; z < 3; z++)
		{
			if (z == 2)
			{
				form_id = static_cast<Intern::t_e_forms>(Intern::mapping[i].id);
				break;
			}
			if (format_str.find(Intern::mapping[i].words[z], 0) == std::string::npos)
				break;
		}
	}

	switch (form_id)
	{
		case Intern::E_PresidentialPardonForm:
			return new PresidentialPardonForm(target);
		case Intern::E_RobotomyRequestForm:
			return new RobotomyRequestForm(target);
		case Intern::E_ShrubberyCreationForm:
			return new ShrubberyCreationForm(target);
		default:
			throw Intern::UnknownName();
	}
}

Intern::UnknownName::UnknownName(void) throw()
{
}

const char *Intern::UnknownName::what(void) const throw()
{
	return ("Intern error: unknown form name provided.");
}
