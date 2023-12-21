/**
 * @file       fixed_size_node_allocator.inst.cpp
 * @brief
 * @date       2021-03-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>

#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>

namespace km = kerbal::memory;


template class km::fixed_size_node_allocator<int>;
template class km::fixed_size_node_allocator<int, km::monotonic_allocator<int> >;

template class kerbal::container::forward_list<int, km::fixed_size_node_allocator<int> >;
template class kerbal::container::list<int, km::fixed_size_node_allocator<int> >;
template class kerbal::container::single_list<int, km::fixed_size_node_allocator<int> >;

template class kerbal::container::forward_list<int, km::fixed_size_node_allocator<int, km::monotonic_allocator<int> > >;
template class kerbal::container::list<int, km::fixed_size_node_allocator<int, km::monotonic_allocator<int> > >;
template class kerbal::container::single_list<int, km::fixed_size_node_allocator<int, km::monotonic_allocator<int> > >;


template
void kerbal::algorithm::swap(
	km::fixed_size_node_allocator<int> &,
	km::fixed_size_node_allocator<int> &
);

template
void kerbal::algorithm::swap(
	km::fixed_size_node_allocator<int, km::monotonic_allocator<int> > &,
	km::fixed_size_node_allocator<int, km::monotonic_allocator<int> > &
);
