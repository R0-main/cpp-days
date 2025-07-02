/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:31 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/02 15:07:34 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <list>

template <typename D>
class PmergeMe
{
  private:
	D container;

  public:
	PmergeMe(){}

	PmergeMe(std::list<long> ints)
	{
		(void)ints;
	}

	PmergeMe(const PmergeMe &other)
	{
		(void)other;
	}

	PmergeMe &operator=(const PmergeMe &other)
	{
		(void)other;
	}

	~PmergeMe(){}
};
