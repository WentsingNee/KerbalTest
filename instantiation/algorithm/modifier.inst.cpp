/**
 * @file       modifier.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/modifier.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};


template CtgIter<int>::type kerbal::algorithm::copy(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::copy(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::copy(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::copy(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::copy(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::copy_if(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::copy_if(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::copy_if(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::copy_if(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::copy_if(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&));

template CtgIter<int>::type kerbal::algorithm::copy_backward(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::copy_backward(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::copy_backward(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::copy_backward_if(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&));
template RasIter<int>::type kerbal::algorithm::copy_backward_if(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, bool(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::copy_backward_if(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&));

template CtgIter<int>::type kerbal::algorithm::move(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::move(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::move(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::move(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::move(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::move_backward(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::move_backward(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::move_backward(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::merge(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::merge(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::merge(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::merge(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::merge(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::reverse(CtgIter<int>::type, CtgIter<int>::type);
template void kerbal::algorithm::reverse(RasIter<int>::type, RasIter<int>::type);
template void kerbal::algorithm::reverse(BdrIter<int>::type, BdrIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::reverse_copy(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::reverse_copy(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::reverse_copy(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);

template CtgIter<int>::type kerbal::algorithm::rotate(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::rotate(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::rotate(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::rotate(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::rotate(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);

template void kerbal::algorithm::inplace_merge(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template CtgIter<int>::type kerbal::algorithm::rotate_copy(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template RasIter<int>::type kerbal::algorithm::rotate_copy(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template BdrIter<int>::type kerbal::algorithm::rotate_copy(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template FwlIter<int>::type kerbal::algorithm::rotate_copy(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwdIter<int>::type kerbal::algorithm::rotate_copy(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);

template void kerbal::algorithm::replace_if(CtgIter<int>::type, CtgIter<int>::type, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(RasIter<int>::type, RasIter<int>::type, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(BdrIter<int>::type, BdrIter<int>::type, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(FwlIter<int>::type, FwlIter<int>::type, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(FwdIter<int>::type, FwdIter<int>::type, bool(*)(const int&), const int&);

template void kerbal::algorithm::replace(CtgIter<int>::type, CtgIter<int>::type, const int&, const int&);
template void kerbal::algorithm::replace(RasIter<int>::type, RasIter<int>::type, const int&, const int&);
template void kerbal::algorithm::replace(BdrIter<int>::type, BdrIter<int>::type, const int&, const int&);
template void kerbal::algorithm::replace(FwlIter<int>::type, FwlIter<int>::type, const int&, const int&);
template void kerbal::algorithm::replace(FwdIter<int>::type, FwdIter<int>::type, const int&, const int&);

template void kerbal::algorithm::fill(CtgIter<int>::type, CtgIter<int>::type, const int&);
template void kerbal::algorithm::fill(RasIter<int>::type, RasIter<int>::type, const int&);
template void kerbal::algorithm::fill(BdrIter<int>::type, BdrIter<int>::type, const int&);
template void kerbal::algorithm::fill(FwlIter<int>::type, FwlIter<int>::type, const int&);
template void kerbal::algorithm::fill(FwdIter<int>::type, FwdIter<int>::type, const int&);

template CtgIter<int>::type kerbal::algorithm::transform(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, int(*)(const int&));
template RasIter<int>::type kerbal::algorithm::transform(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, int(*)(const int&));
template BdrIter<int>::type kerbal::algorithm::transform(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, int(*)(const int&));
template FwlIter<int>::type kerbal::algorithm::transform(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, int(*)(const int&));
template FwdIter<int>::type kerbal::algorithm::transform(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, int(*)(const int&));

template CtgIter<int>::type kerbal::algorithm::transform(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type, int(*)(const int&, const int&));
template RasIter<int>::type kerbal::algorithm::transform(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, RasIter<int>::type, int(*)(const int&, const int&));
template BdrIter<int>::type kerbal::algorithm::transform(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type, int(*)(const int&, const int&));
template FwlIter<int>::type kerbal::algorithm::transform(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type, int(*)(const int&, const int&));
template FwdIter<int>::type kerbal::algorithm::transform(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type, int(*)(const int&, const int&));

template void kerbal::algorithm::iota(CtgIter<int>::type, CtgIter<int>::type, const int&);
template void kerbal::algorithm::iota(RasIter<int>::type, RasIter<int>::type, const int&);
template void kerbal::algorithm::iota(BdrIter<int>::type, BdrIter<int>::type, const int&);
template void kerbal::algorithm::iota(FwlIter<int>::type, FwlIter<int>::type, const int&);
template void kerbal::algorithm::iota(FwdIter<int>::type, FwdIter<int>::type, const int&);

template CtgIter<int>::type kerbal::algorithm::unique(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::unique(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::unique(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::unique(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::unique(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);
