/**
 * @file       flat_ordered.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_ordered.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};

template class kerbal::container::flat_ordered<int, int, cmp_fnptr<int>::type>;
template kerbal::container::flat_ordered<int, int, cmp_fnptr<int>::type>::flat_ordered(const_pointer, const_pointer, int);
