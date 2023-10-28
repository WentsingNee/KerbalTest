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

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/partition.hpp>


template CtgIter<int>::type kerbal::algorithm::is_partitioned_until(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::is_partitioned_until(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::is_partitioned_until(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::is_partitioned_until(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::is_partitioned_until(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template bool kerbal::algorithm::is_partitioned(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template bool kerbal::algorithm::is_partitioned(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template CtgIter<int>::type kerbal::algorithm::partition(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::partition(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::partition(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::partition(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::partition(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));
