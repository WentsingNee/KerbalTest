/**
 * @file       linked_stack.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/linked_stack.hpp>

namespace kc = kerbal::container;


template class kc::linked_stack<int>;
template class kc::linked_stack<int[8]>;



struct Recursive
{
		kc::linked_stack<Recursive> data;

		bool operator==(const Recursive & with) const;
		bool operator!=(const Recursive & with) const;
		bool operator<(const Recursive & with) const;
		bool operator>(const Recursive & with) const;
		bool operator<=(const Recursive & with) const;
		bool operator>=(const Recursive & with) const;
};

template class
kc::linked_stack<Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::linked_stack<ku::noncopyable> & lhs, kc::linked_stack<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
