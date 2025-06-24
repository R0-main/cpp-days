/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/24 08:54:06 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
  private:
	typedef enum
	{
		__E_FORMS_NONE__ = -1,
		E_PresidentialPardonForm,
		E_RobotomyRequestForm,
		E_ShrubberyCreationForm,
		__E_FORMS_COUNT__
	} t_e_forms;

	typedef struct
	{
		const char		*words[2];
		t_e_forms		id;
	} t_mapping;

	static t_mapping	mapping[Intern::__E_FORMS_COUNT__];

  public:
	Intern(Intern &other);
	Intern(void);
	Intern &operator=(Intern &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target) const;

	class UnknownName : public std::exception
	{
		public:
		UnknownName(void) throw();
		const char *what(void) const throw();
	};
};
