/**
 * @file       set.inst.cpp
 * @brief
 * @date       2021-06-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/set/includes.hpp>
#include <kerbal/algorithm/set/set_difference.hpp>
#include <kerbal/algorithm/set/set_intersection.hpp>
#include <kerbal/algorithm/set/set_symmetric_difference.hpp>
#include <kerbal/algorithm/set/set_union.hpp>


template <typename T, typename U>
struct bicmp_fnptr
{
		typedef bool(*type)(const T&, const U&);
};

template bool kerbal::algorithm::includes(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template bool kerbal::algorithm::includes(CtgIter<int>::type, CtgIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template bool kerbal::algorithm::includes(CtgIter<int>::type, CtgIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template bool kerbal::algorithm::includes(CtgIter<int>::type, CtgIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template bool kerbal::algorithm::includes(CtgIter<int>::type, CtgIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);
template bool kerbal::algorithm::includes(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template bool kerbal::algorithm::includes(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template bool kerbal::algorithm::includes(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template bool kerbal::algorithm::includes(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);



template CtgIter<int>::type kerbal::algorithm::set_difference(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::set_difference(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::set_difference(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::set_difference(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::set_difference(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);



template CtgIter<int>::type kerbal::algorithm::set_intersection(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::set_intersection(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::set_intersection(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::set_intersection(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::set_intersection(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);



template CtgIter<int>::type kerbal::algorithm::set_symmetric_difference(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::set_symmetric_difference(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::set_symmetric_difference(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::set_symmetric_difference(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::set_symmetric_difference(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);



template CtgIter<int>::type kerbal::algorithm::set_union(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::set_union(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::set_union(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::set_union(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::set_union(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);
