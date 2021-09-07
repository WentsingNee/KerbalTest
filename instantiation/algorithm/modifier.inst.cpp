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

#include <kerbal/algorithm/modifier.hpp>

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


template CtgIter kerbal::algorithm::copy(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::copy(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::copy(BdrIter, BdrIter, BdrIter);
template FwlIter kerbal::algorithm::copy(FwlIter, FwlIter, FwlIter);
template FwdIter kerbal::algorithm::copy(FwdIter, FwdIter, FwdIter);

template CtgIter kerbal::algorithm::copy_if(CtgIter, CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::copy_if(RasIter, RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::copy_if(BdrIter, BdrIter, BdrIter, bool(*)(const int&));
template FwlIter kerbal::algorithm::copy_if(FwlIter, FwlIter, FwlIter, bool(*)(const int&));
template FwdIter kerbal::algorithm::copy_if(FwdIter, FwdIter, FwdIter, bool(*)(const int&));

template CtgIter kerbal::algorithm::copy_backward(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::copy_backward(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::copy_backward(BdrIter, BdrIter, BdrIter);

template CtgIter kerbal::algorithm::copy_backward_if(CtgIter, CtgIter, CtgIter, bool(*)(const int&));
template RasIter kerbal::algorithm::copy_backward_if(RasIter, RasIter, RasIter, bool(*)(const int&));
template BdrIter kerbal::algorithm::copy_backward_if(BdrIter, BdrIter, BdrIter, bool(*)(const int&));

template CtgIter kerbal::algorithm::move(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::move(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::move(BdrIter, BdrIter, BdrIter);
template FwlIter kerbal::algorithm::move(FwlIter, FwlIter, FwlIter);
template FwdIter kerbal::algorithm::move(FwdIter, FwdIter, FwdIter);

template CtgIter kerbal::algorithm::move_backward(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::move_backward(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::move_backward(BdrIter, BdrIter, BdrIter);

template CtgIter kerbal::algorithm::merge(CtgIter, CtgIter, CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::merge(RasIter, RasIter, RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::merge(BdrIter, BdrIter, BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::merge(FwlIter, FwlIter, FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::merge(FwdIter, FwdIter, FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template void kerbal::algorithm::reverse(CtgIter, CtgIter);
template void kerbal::algorithm::reverse(RasIter, RasIter);
template void kerbal::algorithm::reverse(BdrIter, BdrIter);

template CtgIter kerbal::algorithm::reverse_copy(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::reverse_copy(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::reverse_copy(BdrIter, BdrIter, BdrIter);

template CtgIter kerbal::algorithm::rotate(CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::rotate(RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::rotate(BdrIter, BdrIter, BdrIter);
template FwlIter kerbal::algorithm::rotate(FwlIter, FwlIter, FwlIter);
template FwdIter kerbal::algorithm::rotate(FwdIter, FwdIter, FwdIter);

template void kerbal::algorithm::inplace_merge(CtgIter, CtgIter, CtgIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(RasIter, RasIter, RasIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(BdrIter, BdrIter, BdrIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(FwlIter, FwlIter, FwlIter, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge(FwdIter, FwdIter, FwdIter, cmp_fnptr<int>::type);

template CtgIter kerbal::algorithm::rotate_copy(CtgIter, CtgIter, CtgIter, CtgIter);
template RasIter kerbal::algorithm::rotate_copy(RasIter, RasIter, RasIter, RasIter);
template BdrIter kerbal::algorithm::rotate_copy(BdrIter, BdrIter, BdrIter, BdrIter);
template FwlIter kerbal::algorithm::rotate_copy(FwlIter, FwlIter, FwlIter, FwlIter);
template FwdIter kerbal::algorithm::rotate_copy(FwdIter, FwdIter, FwdIter, FwdIter);

template void kerbal::algorithm::replace_if(CtgIter, CtgIter, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(RasIter, RasIter, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(BdrIter, BdrIter, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(FwlIter, FwlIter, bool(*)(const int&), const int&);
template void kerbal::algorithm::replace_if(FwdIter, FwdIter, bool(*)(const int&), const int&);

template void kerbal::algorithm::replace(CtgIter, CtgIter, const int&, const int&);
template void kerbal::algorithm::replace(RasIter, RasIter, const int&, const int&);
template void kerbal::algorithm::replace(BdrIter, BdrIter, const int&, const int&);
template void kerbal::algorithm::replace(FwlIter, FwlIter, const int&, const int&);
template void kerbal::algorithm::replace(FwdIter, FwdIter, const int&, const int&);

template void kerbal::algorithm::fill(CtgIter, CtgIter, const int&);
template void kerbal::algorithm::fill(RasIter, RasIter, const int&);
template void kerbal::algorithm::fill(BdrIter, BdrIter, const int&);
template void kerbal::algorithm::fill(FwlIter, FwlIter, const int&);
template void kerbal::algorithm::fill(FwdIter, FwdIter, const int&);

template CtgIter kerbal::algorithm::transform(CtgIter, CtgIter, CtgIter, int(*)(const int&));
template RasIter kerbal::algorithm::transform(RasIter, RasIter, RasIter, int(*)(const int&));
template BdrIter kerbal::algorithm::transform(BdrIter, BdrIter, BdrIter, int(*)(const int&));
template FwlIter kerbal::algorithm::transform(FwlIter, FwlIter, FwlIter, int(*)(const int&));
template FwdIter kerbal::algorithm::transform(FwdIter, FwdIter, FwdIter, int(*)(const int&));

template CtgIter kerbal::algorithm::transform(CtgIter, CtgIter, CtgIter, CtgIter, int(*)(const int&, const int&));
template RasIter kerbal::algorithm::transform(RasIter, RasIter, RasIter, RasIter, int(*)(const int&, const int&));
template BdrIter kerbal::algorithm::transform(BdrIter, BdrIter, BdrIter, BdrIter, int(*)(const int&, const int&));
template FwlIter kerbal::algorithm::transform(FwlIter, FwlIter, FwlIter, FwlIter, int(*)(const int&, const int&));
template FwdIter kerbal::algorithm::transform(FwdIter, FwdIter, FwdIter, FwdIter, int(*)(const int&, const int&));

template void kerbal::algorithm::iota(CtgIter, CtgIter, const int&);
template void kerbal::algorithm::iota(RasIter, RasIter, const int&);
template void kerbal::algorithm::iota(BdrIter, BdrIter, const int&);
template void kerbal::algorithm::iota(FwlIter, FwlIter, const int&);
template void kerbal::algorithm::iota(FwdIter, FwdIter, const int&);

template CtgIter kerbal::algorithm::unique(CtgIter, CtgIter, cmp_fnptr<int>::type);
template RasIter kerbal::algorithm::unique(RasIter, RasIter, cmp_fnptr<int>::type);
template BdrIter kerbal::algorithm::unique(BdrIter, BdrIter, cmp_fnptr<int>::type);
template FwlIter kerbal::algorithm::unique(FwlIter, FwlIter, cmp_fnptr<int>::type);
template FwdIter kerbal::algorithm::unique(FwdIter, FwdIter, cmp_fnptr<int>::type);
