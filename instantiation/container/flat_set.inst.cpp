/**
 * @file       flat_set.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_set.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};

template class kerbal::container::flat_set<int, cmp_fnptr<int>::type>;
template class kerbal::container::flat_multiset<int, cmp_fnptr<int>::type>;
template kerbal::container::flat_set<int, cmp_fnptr<int>::type>::flat_set(const_pointer, const_pointer, int);
template kerbal::container::flat_multiset<int, cmp_fnptr<int>::type>::flat_multiset(const_pointer, const_pointer, int);


#include <string>

template class kerbal::container::flat_set<std::string, cmp_fnptr<std::string>::type>;
template class kerbal::container::flat_multiset<std::string, cmp_fnptr<std::string>::type>;
template kerbal::container::flat_set<std::string, cmp_fnptr<std::string>::type>::flat_set(const_pointer, const_pointer, int);
template kerbal::container::flat_multiset<std::string, cmp_fnptr<std::string>::type>::flat_multiset(const_pointer, const_pointer, int);
