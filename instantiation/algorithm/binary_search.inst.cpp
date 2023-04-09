/**
 * @file       binary_search.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/binary_search.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};

#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>

#include <deque>


template <typename T> struct CtgIter { typedef T* type; };
template <typename T> struct RasIter { typedef typename std::deque<T>::iterator type; };
template <typename T> struct BdrIter { typedef typename kerbal::container::list<T>::iterator type; };
template <typename T> struct FwlIter { typedef typename kerbal::container::forward_list<T>::iterator type; };
template <typename T> struct FwdIter { typedef typename kerbal::container::single_list<T>::iterator type; };


template CtgIter<int>::type kerbal::algorithm::lower_bound(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::lower_bound(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::lower_bound(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::lower_bound_backward(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound_backward(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound_backward(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::upper_bound(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::upper_bound(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::upper_bound(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::upper_bound_backward(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound_backward(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound_backward(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);

template std::pair<CtgIter<int>::type, CtgIter<int>::type> kerbal::algorithm::equal_range(CtgIter<int>::type, CtgIter<int>::type, int const&, cmp_fnptr<int>::type);
template std::pair<RasIter<int>::type, RasIter<int>::type> kerbal::algorithm::equal_range(RasIter<int>::type, RasIter<int>::type, int const&, cmp_fnptr<int>::type);
template std::pair<BdrIter<int>::type, BdrIter<int>::type> kerbal::algorithm::equal_range(BdrIter<int>::type, BdrIter<int>::type, int const&, cmp_fnptr<int>::type);
template std::pair<FwlIter<int>::type, FwlIter<int>::type> kerbal::algorithm::equal_range(FwlIter<int>::type, FwlIter<int>::type, int const&, cmp_fnptr<int>::type);
template std::pair<FwdIter<int>::type, FwdIter<int>::type> kerbal::algorithm::equal_range(FwdIter<int>::type, FwdIter<int>::type, int const&, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::lower_bound_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::lower_bound_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::lower_bound_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::upper_bound_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::upper_bound_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::upper_bound_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::algorithm::binary_search(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);

template bool kerbal::algorithm::binary_search_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);
