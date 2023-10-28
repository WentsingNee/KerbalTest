/**
 * @file       sequence_compare.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/compare/sequence_compare.hpp>


template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};


template bool kerbal::compare::sequence_equal_to(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_not_equal_to(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_less(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_greater(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_less_equal(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_greater_equal(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);
