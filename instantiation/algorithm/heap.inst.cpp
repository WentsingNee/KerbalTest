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

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/heap.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};


template void kerbal::algorithm::push_heap(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::push_heap(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::push_heap(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::pop_heap(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::pop_heap(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::pop_heap(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::sort_heap(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort_heap(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort_heap(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::is_heap_until(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::is_heap_until(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::is_heap_until(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::is_heap_until(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::is_heap_until(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template bool kerbal::algorithm::is_heap(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::is_heap(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::make_heap(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::make_heap(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::make_heap(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
