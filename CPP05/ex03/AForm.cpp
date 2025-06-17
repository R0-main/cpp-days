/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:33:25 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 12:15:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>
#include <string>

AForm::AForm(const AForm &b) : name(b.name), is_signed(b.is_signed),
	min_grade_sign(b.min_grade_sign), min_grade_execute(b.min_grade_execute), target(b.target)
{
}

AForm::AForm(std::string name, unsigned char min_grade_sign,
	unsigned char min_grade_execute) : name(name), is_signed(false),
	min_grade_sign(min_grade_sign), min_grade_execute(min_grade_execute), target("")
{
	if (min_grade_sign < LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	if (min_grade_sign > HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (min_grade_execute < LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	if (min_grade_execute > HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
}

std::string AForm::_toString(int d) const throw()
{
	std::ostringstream oss;
	oss << d;
	return (oss.str());
}

const std::string AForm::getFormData(void) const throw()
{
	std::string str;
	str.append(this->name);
	str.append(", ");
	str.append("is_signed : ");
	str.append(this->is_signed ? "true" : "false");
	str.append(", ");
	str.append("min_grade_sign : ");
	str.append(this->_toString(this->min_grade_sign));
	str.append(", ");
	str.append("min_grade_execute : ");
	str.append(this->_toString(this->min_grade_execute));
	return (str);
}

void AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->min_grade_sign)
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}


void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->min_grade_execute)
		throw AForm::GradeTooLowException();
	if (this->is_signed == false)
		throw AForm::NotSignedException();
}

AForm::~AForm(void) throw()
{
}

const AForm &AForm::operator=(const AForm &b)
{
	*((unsigned char *)&this->min_grade_sign) = b.min_grade_sign;
	*((unsigned char *)&this->min_grade_execute) = b.min_grade_execute;
	*((std::string *)&this->name) = b.name;
	this->target = b.target;
	this->is_signed = b.is_signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
	out << b.getFormData();
	return (out);
}

std::string AForm::getName() const throw()
{
	return (this->name);
}

AForm::GradeTooLowException::GradeTooLowException(void) throw()
{
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("form grade is too high");
}

AForm::GradeTooHighException::GradeTooHighException(void) throw()
{
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("form grade is too high");
}

AForm::NotSignedException::NotSignedException(void) throw()
{
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("form is not signed");
}
