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

#include <deque>
#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>

typedef int* CtgIter;
typedef std::deque<int>::iterator RasIter;
typedef kerbal::container::list<int>::iterator BdrIter;
typedef kerbal::container::forward_list<int>::iterator FwlIter;
typedef kerbal::container::single_list<int>::iterator FwdIter;


template CtgIter kerbal::algorithm::lower_bound(CtgIter, CtgIter, const int&, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::lower_bound(RasIter, RasIter, const int&, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::lower_bound(BdrIter, BdrIter, const int&, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::lower_bound(FwlIter, FwlIter, const int&, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::lower_bound(FwdIter, FwdIter, const int&, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::lower_bound_backward(CtgIter, CtgIter, const int&, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::lower_bound_backward(RasIter, RasIter, const int&, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::lower_bound_backward(BdrIter, BdrIter, const int&, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::upper_bound(CtgIter, CtgIter, const int&, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::upper_bound(RasIter, RasIter, const int&, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::upper_bound(BdrIter, BdrIter, const int&, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::upper_bound(FwlIter, FwlIter, const int&, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::upper_bound(FwdIter, FwdIter, const int&, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::upper_bound_backward(CtgIter, CtgIter, const int&, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::upper_bound_backward(RasIter, RasIter, const int&, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::upper_bound_backward(BdrIter, BdrIter, const int&, cmp_fnptr<int>::type);

template std::pair<CtgIter, CtgIter> kerbal::algorithm::equal_range(CtgIter, CtgIter, int const&, cmp_fnptr<int>::type);
template std::pair<RasIter, RasIter> kerbal::algorithm::equal_range(RasIter, RasIter, int const&, cmp_fnptr<int>::type);
template std::pair<BdrIter, BdrIter> kerbal::algorithm::equal_range(BdrIter, BdrIter, int const&, cmp_fnptr<int>::type);
template std::pair<FwlIter, FwlIter> kerbal::algorithm::equal_range(FwlIter, FwlIter, int const&, cmp_fnptr<int>::type);
template std::pair<FwdIter, FwdIter> kerbal::algorithm::equal_range(FwdIter, FwdIter, int const&, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::lower_bound_hint(CtgIter, CtgIter, const int&, CtgIter, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::lower_bound_hint(RasIter, RasIter, const int&, RasIter, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::lower_bound_hint(BdrIter, BdrIter, const int&, BdrIter, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::lower_bound_hint(FwlIter, FwlIter, const int&, FwlIter, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::lower_bound_hint(FwdIter, FwdIter, const int&, FwdIter, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::upper_bound_hint(CtgIter, CtgIter, const int&, CtgIter, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::upper_bound_hint(RasIter, RasIter, const int&, RasIter, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::upper_bound_hint(BdrIter, BdrIter, const int&, BdrIter, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::upper_bound_hint(FwlIter, FwlIter, const int&, FwlIter, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::upper_bound_hint(FwdIter, FwdIter, const int&, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::algorithm::binary_search(CtgIter, CtgIter, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(RasIter, RasIter, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(BdrIter, BdrIter, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwlIter, FwlIter, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwdIter, FwdIter, const int&, cmp_fnptr<int>::type);

template bool kerbal::algorithm::binary_search_hint(CtgIter, CtgIter, const int&, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(RasIter, RasIter, const int&, RasIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(BdrIter, BdrIter, const int&, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwlIter, FwlIter, const int&, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwdIter, FwdIter, const int&, FwdIter, cmp_fnptr<int>::type);
