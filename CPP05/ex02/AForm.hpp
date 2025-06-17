/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:33:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/17 09:39:08 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool is_signed;
	const unsigned char min_grade_sign;
	const unsigned char min_grade_execute;

	std::string _toString(int d) const throw();

  public:
	AForm(const AForm &b);
	AForm(std::string name, unsigned char min_grade_sign,
		unsigned char min_grade_execute);
	const AForm &operator=(const AForm &b);
	virtual ~AForm() throw() = 0;

	void beSigned(Bureaucrat b);

	std::string getName() const throw();

	const std::string getFormData(void) const throw();

	virtual void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
		GradeTooHighException(void) throw();
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		GradeTooLowException(void) throw();
		const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
		NotSignedException(void) throw();
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &b);
