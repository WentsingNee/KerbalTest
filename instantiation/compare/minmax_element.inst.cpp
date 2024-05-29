/**
 * @file       minmax_element.inst.cpp
 * @brief
 * @date       2024-05-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/compare/minmax_element.hpp>


template CtgIter<int>::type kerbal::compare::min_element(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&, const int&));
template RasIter<int>::type kerbal::compare::min_element(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&, const int&));
template BdrIter<int>::type kerbal::compare::min_element(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&, const int&));
template FwlIter<int>::type kerbal::compare::min_element(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&, const int&));
template FwdIter<int>::type kerbal::compare::min_element(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&, const int&));

template CtgIter<int>::type kerbal::compare::max_element(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&, const int&));
template RasIter<int>::type kerbal::compare::max_element(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&, const int&));
template BdrIter<int>::type kerbal::compare::max_element(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&, const int&));
template FwlIter<int>::type kerbal::compare::max_element(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&, const int&));
template FwdIter<int>::type kerbal::compare::max_element(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&, const int&));

template kerbal::utility::compressed_pair<CtgIter<int>::type, CtgIter<int>::type> kerbal::compare::minmax_element(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&, const int&));
template kerbal::utility::compressed_pair<RasIter<int>::type, RasIter<int>::type> kerbal::compare::minmax_element(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&, const int&));
template kerbal::utility::compressed_pair<BdrIter<int>::type, BdrIter<int>::type> kerbal::compare::minmax_element(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&, const int&));
template kerbal::utility::compressed_pair<FwlIter<int>::type, FwlIter<int>::type> kerbal::compare::minmax_element(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&, const int&));
template kerbal::utility::compressed_pair<FwdIter<int>::type, FwdIter<int>::type> kerbal::compare::minmax_element(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&, const int&));
