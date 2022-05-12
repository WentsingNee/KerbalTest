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

#include <kerbal/compare/sequence_compare.hpp>

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


template bool kerbal::compare::sequence_equal_to(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_equal_to(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_not_equal_to(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_not_equal_to(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_less(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_greater(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_less_equal(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_less_equal(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::compare::sequence_greater_equal(CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::compare::sequence_greater_equal(FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);
