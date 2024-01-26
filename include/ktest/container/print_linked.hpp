/**
 * @file       print_linked.hpp
 * @brief
 * @date       2024-01-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_CONTAINER_PRINT_LINKED_HPP
#define KTEST_CONTAINER_PRINT_LINKED_HPP

#include <iostream>


namespace ktest
{

	namespace container
	{

		template <typename Container>
		void print_linked_with_address(const Container & l)
		{
			typedef typename Container::const_iterator const_iterator;
			const_iterator end = l.cend();
			for (const_iterator it = l.cbegin(); it != end; ++it) {
				std::cout << *it << "   " << &*it << std::endl;
			}
			std::cout << std::endl;
		}

		template <typename Container>
		void print_linked_reverse_with_address(const Container & l)
		{
			typedef typename Container::const_reverse_iterator const_reverse_iterator;
			const_reverse_iterator rend = l.crend();
			for (const_reverse_iterator it = l.crbegin(); it != rend; ++it) {
				std::cout << *it << "   " << &*it << std::endl;
			}
			std::cout << std::endl;
		}

	} // namespace container

} // namespace ktest

#endif // KTEST_CONTAINER_PRINT_LINKED_HPP
