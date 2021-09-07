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

#include <kerbal/algorithm/querier.hpp>

#include <deque>
#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>

typedef int* CtgIter;
typedef std::deque<int>::iterator RasIter;
typedef kerbal::container::list<int>::iterator BdrIter;
typedef kerbal::container::forward_list<int>::iterator FwlIter;
typedef kerbal::container::single_list<int>::iterator FwdIter;


template CtgIter kerbal::algorithm::find_if(CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::find_if(RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::find_if(BdrIter, BdrIter, bool(*)(const int&));
template FwlIter kerbal::algorithm::find_if(FwlIter, FwlIter, bool(*)(const int&));
template FwdIter kerbal::algorithm::find_if(FwdIter, FwdIter, bool(*)(const int&));

template CtgIter kerbal::algorithm::find(CtgIter, CtgIter, const int&);
template RasIter kerbal::algorithm::find(RasIter, RasIter, const int&);
template BdrIter kerbal::algorithm::find(BdrIter, BdrIter, const int&);
template FwlIter kerbal::algorithm::find(FwlIter, FwlIter, const int&);
template FwdIter kerbal::algorithm::find(FwdIter, FwdIter, const int&);

template CtgIter kerbal::algorithm::find_if_not(CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::find_if_not(RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::find_if_not(BdrIter, BdrIter, bool(*)(const int&));
template FwlIter kerbal::algorithm::find_if_not(FwlIter, FwlIter, bool(*)(const int&));
template FwdIter kerbal::algorithm::find_if_not(FwdIter, FwdIter, bool(*)(const int&));

template bool kerbal::algorithm::all_of(CtgIter, CtgIter, bool(*)(const int&));
template bool kerbal::algorithm::all_of(RasIter, RasIter, bool(*)(const int&));
template bool kerbal::algorithm::all_of(BdrIter, BdrIter, bool(*)(const int&));
template bool kerbal::algorithm::all_of(FwlIter, FwlIter, bool(*)(const int&));
template bool kerbal::algorithm::all_of(FwdIter, FwdIter, bool(*)(const int&));

template bool kerbal::algorithm::any_of(CtgIter, CtgIter, bool(*)(const int&));
template bool kerbal::algorithm::any_of(RasIter, RasIter, bool(*)(const int&));
template bool kerbal::algorithm::any_of(BdrIter, BdrIter, bool(*)(const int&));
template bool kerbal::algorithm::any_of(FwlIter, FwlIter, bool(*)(const int&));
template bool kerbal::algorithm::any_of(FwdIter, FwdIter, bool(*)(const int&));

template bool kerbal::algorithm::none_of(CtgIter, CtgIter, bool(*)(const int&));
template bool kerbal::algorithm::none_of(RasIter, RasIter, bool(*)(const int&));
template bool kerbal::algorithm::none_of(BdrIter, BdrIter, bool(*)(const int&));
template bool kerbal::algorithm::none_of(FwlIter, FwlIter, bool(*)(const int&));
template bool kerbal::algorithm::none_of(FwdIter, FwdIter, bool(*)(const int&));

template void(*kerbal::algorithm::for_each(CtgIter, CtgIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(RasIter, RasIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(BdrIter, BdrIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(FwlIter, FwlIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::for_each(FwdIter, FwdIter, void(*)(const int&)) )(const int&);

template void(*kerbal::algorithm::rfor_each(CtgIter, CtgIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::rfor_each(RasIter, RasIter, void(*)(const int&)) )(const int&);
template void(*kerbal::algorithm::rfor_each(BdrIter, BdrIter, void(*)(const int&)) )(const int&);

template size_t kerbal::algorithm::count_if(CtgIter, CtgIter, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(RasIter, RasIter, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(BdrIter, BdrIter, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(FwlIter, FwlIter, bool(*)(const int&));
template size_t kerbal::algorithm::count_if(FwdIter, FwdIter, bool(*)(const int&));

template size_t kerbal::algorithm::count(CtgIter, CtgIter, const int&);
template size_t kerbal::algorithm::count(RasIter, RasIter, const int&);
template size_t kerbal::algorithm::count(BdrIter, BdrIter, const int&);
template size_t kerbal::algorithm::count(FwlIter, FwlIter, const int&);
template size_t kerbal::algorithm::count(FwdIter, FwdIter, const int&);

template CtgIter kerbal::algorithm::find_first_of(CtgIter, CtgIter, CtgIter, CtgIter, bool(*)(const int&, const int&));
template RasIter kerbal::algorithm::find_first_of(RasIter, RasIter, RasIter, RasIter, bool(*)(const int&, const int&));
template BdrIter kerbal::algorithm::find_first_of(BdrIter, BdrIter, BdrIter, BdrIter, bool(*)(const int&, const int&));
template FwlIter kerbal::algorithm::find_first_of(FwlIter, FwlIter, FwlIter, FwlIter, bool(*)(const int&, const int&));
template FwdIter kerbal::algorithm::find_first_of(FwdIter, FwdIter, FwdIter, FwdIter, bool(*)(const int&, const int&));

template CtgIter kerbal::algorithm::adjacent_find(CtgIter, CtgIter, bool(*)(const int&, const int&));
template RasIter kerbal::algorithm::adjacent_find(RasIter, RasIter, bool(*)(const int&, const int&));
template BdrIter kerbal::algorithm::adjacent_find(BdrIter, BdrIter, bool(*)(const int&, const int&));
template FwlIter kerbal::algorithm::adjacent_find(FwlIter, FwlIter, bool(*)(const int&, const int&));
template FwdIter kerbal::algorithm::adjacent_find(FwdIter, FwdIter, bool(*)(const int&, const int&));

template CtgIter kerbal::algorithm::min_element(CtgIter, CtgIter, bool(*)(const int&, const int&));
template RasIter kerbal::algorithm::min_element(RasIter, RasIter, bool(*)(const int&, const int&));
template BdrIter kerbal::algorithm::min_element(BdrIter, BdrIter, bool(*)(const int&, const int&));
template FwlIter kerbal::algorithm::min_element(FwlIter, FwlIter, bool(*)(const int&, const int&));
template FwdIter kerbal::algorithm::min_element(FwdIter, FwdIter, bool(*)(const int&, const int&));

template CtgIter kerbal::algorithm::max_element(CtgIter, CtgIter, bool(*)(const int&, const int&));
template RasIter kerbal::algorithm::max_element(RasIter, RasIter, bool(*)(const int&, const int&));
template BdrIter kerbal::algorithm::max_element(BdrIter, BdrIter, bool(*)(const int&, const int&));
template FwlIter kerbal::algorithm::max_element(FwlIter, FwlIter, bool(*)(const int&, const int&));
template FwdIter kerbal::algorithm::max_element(FwdIter, FwdIter, bool(*)(const int&, const int&));

template std::pair<CtgIter, CtgIter> kerbal::algorithm::minmax_element(CtgIter, CtgIter, bool(*)(const int&, const int&));
template std::pair<RasIter, RasIter> kerbal::algorithm::minmax_element(RasIter, RasIter, bool(*)(const int&, const int&));
template std::pair<BdrIter, BdrIter> kerbal::algorithm::minmax_element(BdrIter, BdrIter, bool(*)(const int&, const int&));
template std::pair<FwlIter, FwlIter> kerbal::algorithm::minmax_element(FwlIter, FwlIter, bool(*)(const int&, const int&));
template std::pair<FwdIter, FwdIter> kerbal::algorithm::minmax_element(FwdIter, FwdIter, bool(*)(const int&, const int&));
