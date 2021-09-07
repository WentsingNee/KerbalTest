/**
 * @file       allocator_traits.inst.cpp
 * @brief
 * @date       2021-07-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator_traits.hpp>

#include <memory>

template struct kerbal::memory::allocator_traits<std::allocator<int> >;


#if __cplusplus >= 201703L
#	if __has_include(<memory_resource>)

#	include <memory_resource>

template struct kerbal::memory::allocator_traits<std::pmr::polymorphic_allocator<int> >;

#	endif
#endif
