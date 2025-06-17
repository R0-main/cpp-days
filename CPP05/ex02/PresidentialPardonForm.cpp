/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:01:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 10:07:16 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target(other.target)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	PresidentialPardonForm::AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	PresidentialPardonForm::AForm::execute(executor);

	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
}
