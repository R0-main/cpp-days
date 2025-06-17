/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:33:25 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 11:25:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <sstream>
#include <string>

Form::Form(const Form &b) : name(b.name), is_signed(b.is_signed),
	min_grade_sign(b.min_grade_sign), min_grade_execute(b.min_grade_execute)
{
}

Form::Form(std::string name, unsigned char min_grade_sign,
	unsigned char min_grade_execute) : name(name), is_signed(false),
	min_grade_sign(min_grade_sign), min_grade_execute(min_grade_execute)
{
	if (min_grade_sign < LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (min_grade_sign > HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (min_grade_execute < LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (min_grade_execute > HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

std::string Form::_toString(int d) const throw()
{
	std::ostringstream oss;
	oss << d;
	return (oss.str());
}

const std::string Form::getFormData(void) const throw()
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

void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->min_grade_sign)
		throw Form::GradeTooLowException();
	this->is_signed = true;
}

Form::~Form(void) throw()
{
	std::cout << "test\n";
}

const Form &Form::operator=(const Form &b)
{
	*((unsigned char *)&this->min_grade_sign) = b.min_grade_sign;
	*((unsigned char *)&this->min_grade_execute) = b.min_grade_execute;
	*((std::string *)&this->name) = b.name;
	this->is_signed = b.is_signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
	out << b.getFormData();
	return (out);
}

std::string Form::getName() const throw()
{
	return (this->name);
}

Form::GradeTooLowException::GradeTooLowException(void) throw()
{
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too high");
}

Form::GradeTooHighException::GradeTooHighException(void) throw()
{
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too low");
}
