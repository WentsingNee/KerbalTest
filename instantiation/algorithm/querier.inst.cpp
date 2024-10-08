/**
 * @file       querier.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/querier/find.hpp>
#include <kerbal/algorithm/querier/find_if.hpp>
#include <kerbal/algorithm/querier/find_if_not.hpp>
#include <kerbal/algorithm/querier/all_of.hpp>
#include <kerbal/algorithm/querier/any_of.hpp>
#include <kerbal/algorithm/querier/none_of.hpp>
#include <kerbal/algorithm/querier/for_each.hpp>
#include <kerbal/algorithm/querier/rfor_each.hpp>
#include <kerbal/algorithm/querier/count.hpp>
#include <kerbal/algorithm/querier/count_if.hpp>
#include <kerbal/algorithm/querier/find_first_of.hpp>
#include <kerbal/algorithm/querier/adjacent_find.hpp>


template CtgIter<int>::type kerbal::algorithm::find_if(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::find_if(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::find_if(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::find_if(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::find_if(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template CtgIter<int>::type kerbal::algorithm::find(CtgIter<int>::type, CtgIter<int>::type, const int&);
template RasIter<int>::type kerbal::algorithm::find(RasIter<int>::type, RasIter<int>::type, const int&);
template BdrIter<int>::type kerbal::algorithm::find(BdrIter<int>::type, BdrIter<int>::type, const int&);
template FwlIter<int>::type kerbal::algorithm::find(FwlIter<int>::type, FwlIter<int>::type, const int&);
template FwdIter<int>::type kerbal::algorithm::find(FwdIter<int>::type, FwdIter<int>::type, const int&);

template CtgIter<int>::type kerbal::algorithm::find_if_not(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::find_if_not(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::find_if_not(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::find_if_not(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::find_if_not(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template bool kerbal::algorithm::all_of(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::all_of(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::all_of(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::all_of(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::all_of(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template bool kerbal::algorithm::any_of(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::any_of(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::any_of(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::any_of(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::any_of(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template bool kerbal::algorithm::none_of(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::none_of(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::none_of(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::none_of(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::none_of(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template void(*kerbal::algorithm::for_each(CtgIter<int>::type, CtgIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(RasIter<int>::type, RasIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(BdrIter<int>::type, BdrIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(FwlIter<int>::type, FwlIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(FwdIter<int>::type, FwdIter<int>::type, void(*)(const int&)) )(const int&);

template void(*kerbal::algorithm::rfor_each(CtgIter<int>::type, CtgIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::rfor_each(RasIter<int>::type, RasIter<int>::type, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::rfor_each(BdrIter<int>::type, BdrIter<int>::type, void(*)(const int&)) )(const int&);

template size_t kerbal::algorithm::count_if(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template size_t kerbal::algorithm::count(CtgIter<int>::type, CtgIter<int>::type, const int&);
template size_t kerbal::algorithm::count(RasIter<int>::type, RasIter<int>::type, const int&);
template size_t kerbal::algorithm::count(BdrIter<int>::type, BdrIter<int>::type, const int&);
template size_t kerbal::algorithm::count(FwlIter<int>::type, FwlIter<int>::type, const int&);
template size_t kerbal::algorithm::count(FwdIter<int>::type, FwdIter<int>::type, const int&);

template CtgIter<int>::type kerbal::algorithm::find_first_of(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&, const int&));
template RasIter<int>::type kerbal::algorithm::find_first_of(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, bool(*)(const int&, const int&));
template BdrIter<int>::type kerbal::algorithm::find_first_of(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&, const int&));
template FwlIter<int>::type kerbal::algorithm::find_first_of(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&, const int&));
template FwdIter<int>::type kerbal::algorithm::find_first_of(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&, const int&));

template CtgIter<int>::type kerbal::algorithm::adjacent_find(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&, const int&));
template RasIter<int>::type kerbal::algorithm::adjacent_find(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&, const int&));
template BdrIter<int>::type kerbal::algorithm::adjacent_find(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&, const int&));
template FwlIter<int>::type kerbal::algorithm::adjacent_find(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&, const int&));
template FwdIter<int>::type kerbal::algorithm::adjacent_find(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&, const int&));
