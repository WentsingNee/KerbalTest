/**
 * @file       partition.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/partition.hpp>

#include <deque>
#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>

typedef int* CtgIter;
typedef std::deque<int>::iterator RasIter;
typedef kerbal::container::list<int>::iterator BdrIter;
typedef kerbal::container::forward_list<int>::iterator FwlIter;
typedef kerbal::container::single_list<int>::iterator FwdIter;


template CtgIter kerbal::algorithm::is_partitioned_until(CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::is_partitioned_until(RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::is_partitioned_until(BdrIter, BdrIter, bool(*)(const int&));
template FwlIter kerbal::algorithm::is_partitioned_until(FwlIter, FwlIter, bool(*)(const int&));
template FwdIter kerbal::algorithm::is_partitioned_until(FwdIter, FwdIter, bool(*)(const int&));

template bool kerbal::algorithm::is_partitioned(CtgIter, CtgIter, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(RasIter, RasIter, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(BdrIter, BdrIter, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(FwlIter, FwlIter, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(FwdIter, FwdIter, bool(*)(const int&));

template CtgIter kerbal::algorithm::partition(CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::partition(RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::partition(BdrIter, BdrIter, bool(*)(const int&));
template FwlIter kerbal::algorithm::partition(FwlIter, FwlIter, bool(*)(const int&));
template FwdIter kerbal::algorithm::partition(FwdIter, FwdIter, bool(*)(const int&));
