/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:31 by rguigneb          #+#    #+#             */
/*   Updated: 2025/07/03 13:56:03 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

template <template <typename, typename> class D > class PmergeMe
{
  private:
	typedef D<long, std::allocator<long> > t_long_container;
	typedef D<std::pair<long, long> , std::allocator<std::pair<long, long> > > t_pair_container;
	typedef D<bool , std::allocator<bool > > t_bool_container;
	typedef D<size_t , std::allocator<size_t > > t_size_t_container;

	t_long_container _merge_insertion_sort(t_long_container pairs)
	{
		size_t size = pairs.size();

		if (size <= 1)
			return (pairs);
		if (size == 2)
		{
			if (pairs[0] > pairs[1])
				std::swap(pairs[0], pairs[1]);
			return (pairs);
		}
		t_pair_container new_pairs;
		long left_overs = -1;

		if (size % 2 == 1)
		{
			left_overs = pairs.back();
			pairs.pop_back();
			size -= 1;
		}

		for (size_t i = 0; i < size; i += 2)
		{
			long x = pairs[i];
			long y = pairs[i + 1];

			if (x <= y)
				new_pairs.push_back(std::make_pair(x, y));
			else
				new_pairs.push_back(std::make_pair(y, x));
		}

		t_long_container H;
		for (typename t_pair_container::iterator i = new_pairs.begin(); i != new_pairs.end(); i++)
		{
			H.push_back((*i).second);
		}
		t_long_container S = this->_merge_insertion_sort(H);

		if (S.empty() == false)
		{
			long smallest_a = S[0];
			long b1 = -1;
			for (typename t_pair_container::iterator i = new_pairs.begin(); i != new_pairs.end(); i++)
			{
				if ((*i).second == smallest_a)
				{
					b1 = (*i).first;
					new_pairs.erase(i);
					break ;
				}
			}
			if (b1 != -1)
				S.insert(S.begin(), b1);
		}

		t_long_container pend;
		for (typename t_pair_container::iterator i = new_pairs.begin(); i != new_pairs.end(); i++)
			pend.push_back((*i).first);

		if (left_overs != -1)
			pend.push_back(left_overs);

		if (!pend.empty())
		{
			t_size_t_container insertion_order = _generateInsertionOrder(pend.size());

			for (size_t i = 0; i < insertion_order.size(); ++i)
			{
				long element = pend[insertion_order[i]];
				typename t_long_container::iterator pos = std::lower_bound(S.begin(),
						S.end(), element);
				S.insert(pos, element);
			}
		}
		return (S);
	}

	t_size_t_container _generateJacobsthalSequence(size_t max_index)
	{
		t_size_t_container jacobsthal;
		if (max_index == 0)
			return (jacobsthal);
		jacobsthal.push_back(0);

		if (max_index == 1)
			return (jacobsthal);
		jacobsthal.push_back(1);

		for (size_t i = 2; jacobsthal.back() < max_index; ++i)
		{
			size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
			if (next > max_index)
				break ;
			jacobsthal.push_back(next);
		}

		return (jacobsthal);
	}

	t_size_t_container _generateInsertionOrder(size_t pend_size)
	{
		if (pend_size == 0)
			return (t_size_t_container());

		t_size_t_container jacobsthal = _generateJacobsthalSequence(pend_size);
		t_size_t_container order;
		t_bool_container used(pend_size, false);

		if (pend_size > 0)
		{
			order.push_back(0);
			used[0] = true;
		}
		for (size_t i = 1; i < jacobsthal.size(); ++i)
		{
			size_t start = jacobsthal[i];
			size_t end = (i > 1) ? jacobsthal[i - 1] + 1 : 1;
			for (size_t j = start; j > 0 && j >= end && j < pend_size; --j)
			{
				if (!used[j])
				{
					order.push_back(j);
					used[j] = true;
				}
			}
		}
		for (size_t i = 0; i < pend_size; ++i)
		{
			if (!used[i])
			{
				order.push_back(i);
			}
		}
		return (order);
	}

  public:
	PmergeMe()
	{
	}

	PmergeMe(t_long_container &ints)
	{
		ints = this->_merge_insertion_sort(ints);
	}

	PmergeMe(const PmergeMe &other)
	{
		(void)other;
	}

	PmergeMe &operator=(const PmergeMe &other)
	{
		(void)other;
	}

	~PmergeMe()
	{
	}

	class Timer
	{
		private:
		clock_t _start;
		clock_t _end;

		const char *_name;

		public:
		Timer(const char *name) : _name(name)
		{
			// std::cout << "[" << name << "] Start Timer" << std::endl;
			this->_start = clock();
		}
		~Timer()
		{
			this->_end = clock();

			double duration = static_cast<double>(this->_end - this->_start) / CLOCKS_PER_SEC;
			std::cout << "[" << this->_name << "] Time Taken " << std::fixed << std::setprecision(6) << duration << " sec" << std::endl;
		}
	};
};
