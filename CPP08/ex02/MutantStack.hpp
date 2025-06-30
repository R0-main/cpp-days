/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:41:40 by rguigneb          #+#    #+#             */
/*   Updated: 2025/06/30 14:38:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <iostream>
#include <stack>
#include <vector>

template <typename T,
	typename D = std::deque<T> > class MutantStack : public std::stack<T, D>
{
  public:
	typedef typename D::iterator iterator;
	typedef typename D::const_iterator const_iterator;

	iterator begin() throw()
	{
		return (this->c.begin());
	}

	const_iterator begin() const throw()
	{
		return (this->c.begin());
	}

	iterator end() throw()
	{
		return (this->c.end());
	}

	const_iterator end() const throw()
	{
		return (this->c.end());
	}
};
