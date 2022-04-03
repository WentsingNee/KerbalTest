/**
 * @file       linked_queue.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/linked_queue.hpp>

namespace kc = kerbal::container;


template class kc::linked_queue<int>;
template class kc::linked_queue<int[8]>;
//template class kc::linked_queue<int[8][8]>;



struct Recursive
{
		kc::linked_queue<Recursive> data;

		bool operator==(const Recursive & with) const;
		bool operator!=(const Recursive & with) const;
		bool operator<(const Recursive & with) const;
		bool operator>(const Recursive & with) const;
		bool operator<=(const Recursive & with) const;
		bool operator>=(const Recursive & with) const;
};

template class
kc::linked_queue<Recursive>;
