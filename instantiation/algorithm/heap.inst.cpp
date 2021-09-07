/**
 * @file       heap.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/heap.hpp>

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


template void kerbal::algorithm::push_heap(CtgIter, CtgIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::push_heap(RasIter, RasIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::push_heap(BdrIter, BdrIter, cmp_fnptr<int>::type);

template void kerbal::algorithm::pop_heap(CtgIter, CtgIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::pop_heap(RasIter, RasIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::pop_heap(BdrIter, BdrIter, cmp_fnptr<int>::type);

template void kerbal::algorithm::sort_heap(CtgIter, CtgIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort_heap(RasIter, RasIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort_heap(BdrIter, BdrIter, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::is_heap_until(CtgIter, CtgIter, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::is_heap_until(RasIter, RasIter, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::is_heap_until(BdrIter, BdrIter, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::is_heap_until(FwlIter, FwlIter, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::is_heap_until(FwdIter, FwdIter, cmp_fnptr<int>::type);

template bool kerbal::algorithm::is_heap(CtgIter, CtgIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(RasIter, RasIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(FwdIter, FwdIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(FwlIter, FwlIter, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(BdrIter, BdrIter, cmp_fnptr<int>::type);

template void kerbal::algorithm::make_heap(CtgIter, CtgIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::make_heap(RasIter, RasIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::make_heap(BdrIter, BdrIter, cmp_fnptr<int>::type);
