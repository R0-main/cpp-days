/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 08:56:50 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/16 09:56:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat::Bureaucrat(std::string name, unsigned char grade) : name(name)
{
	if (grade < LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (grade > HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void) throw()
{
	std::cout << "test\n";
}

void Bureaucrat::incrementGrade(void)
{
	if (this->grade - 1 < LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->grade + 1 > HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	this->grade = b.grade;
	*((std::string *)&this->name) = b.name;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}

std::string Bureaucrat::getName(void) const throw()
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade(void) const throw()
{
	return (this->grade);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw()
{
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException: Bureaucrat grade is too high. Grade must be between " STRING(LOWEST_GRADE) " (highest) and " STRING(HIGHEST_GRADE) " (lowest).");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw()
{
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooLowException: Bureaucrat grade is too low. Grade must be between " STRING(LOWEST_GRADE) " (highest) and " STRING(HIGHEST_GRADE) " (lowest).");
}
