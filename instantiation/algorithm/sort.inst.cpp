/**
 * @file       sort.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/sort.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};


#include <kerbal/compare/basic_compare.hpp>

#include <string>

template void kerbal::algorithm::bubble_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::bubble_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::bubble_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::bubble_sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::bubble_sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::heap_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::heap_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::heap_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::insertion_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::insertion_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::insertion_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::directly_insertion_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::directly_insertion_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::directly_insertion_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::intro_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::intro_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::intro_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::nonrecursive_intro_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::nonrecursive_intro_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::nonrecursive_intro_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::merge_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::merge_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::merge_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::merge_sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::merge_sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::inplace_merge_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge_sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::inplace_merge_sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::pigeonhole_sort(CtgIter<short>::type, CtgIter<short>::type);
template void kerbal::algorithm::pigeonhole_sort(RasIter<short>::type, RasIter<short>::type);
template void kerbal::algorithm::pigeonhole_sort(BdrIter<short>::type, BdrIter<short>::type);
template void kerbal::algorithm::pigeonhole_sort(FwlIter<short>::type, FwlIter<short>::type);
template void kerbal::algorithm::pigeonhole_sort(FwdIter<short>::type, FwdIter<short>::type);

template void kerbal::algorithm::pigeonhole_sort(CtgIter<short>::type, CtgIter<short>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::pigeonhole_sort(RasIter<short>::type, RasIter<short>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::pigeonhole_sort(BdrIter<short>::type, BdrIter<short>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::pigeonhole_sort(FwlIter<short>::type, FwlIter<short>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::pigeonhole_sort(FwdIter<short>::type, FwdIter<short>::type, kerbal::type_traits::false_type);

template void kerbal::algorithm::pigeonhole_sort(CtgIter<short>::type, CtgIter<short>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::pigeonhole_sort(RasIter<short>::type, RasIter<short>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::pigeonhole_sort(BdrIter<short>::type, BdrIter<short>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::pigeonhole_sort(FwlIter<short>::type, FwlIter<short>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::pigeonhole_sort(FwdIter<short>::type, FwdIter<short>::type, kerbal::type_traits::true_type);

template void kerbal::algorithm::quick_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::quick_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::quick_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::nonrecursive_qsort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::nonrecursive_qsort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::nonrecursive_qsort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::radix_sort(CtgIter<int>::type, CtgIter<int>::type);
template void kerbal::algorithm::radix_sort(RasIter<int>::type, RasIter<int>::type);
template void kerbal::algorithm::radix_sort(BdrIter<int>::type, BdrIter<int>::type);
template void kerbal::algorithm::radix_sort(FwlIter<int>::type, FwlIter<int>::type);
template void kerbal::algorithm::radix_sort(FwdIter<int>::type, FwdIter<int>::type);

template void kerbal::algorithm::radix_sort(CtgIter<int>::type, CtgIter<int>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::radix_sort(RasIter<int>::type, RasIter<int>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::radix_sort(BdrIter<int>::type, BdrIter<int>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::radix_sort(FwlIter<int>::type, FwlIter<int>::type, kerbal::type_traits::false_type);
template void kerbal::algorithm::radix_sort(FwdIter<int>::type, FwdIter<int>::type, kerbal::type_traits::false_type);

template void kerbal::algorithm::radix_sort(CtgIter<int>::type, CtgIter<int>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::radix_sort(RasIter<int>::type, RasIter<int>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::radix_sort(BdrIter<int>::type, BdrIter<int>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::radix_sort(FwlIter<int>::type, FwlIter<int>::type, kerbal::type_traits::true_type);
template void kerbal::algorithm::radix_sort(FwdIter<int>::type, FwdIter<int>::type, kerbal::type_traits::true_type);

template void kerbal::algorithm::selection_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::selection_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::selection_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::selection_sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::selection_sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

//template void kerbal::algorithm::shell_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
//template void kerbal::algorithm::shell_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
//template void kerbal::algorithm::shell_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::stable_sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::stable_sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::stable_sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::stable_sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::stable_sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::sort(CtgIter<short>::type, CtgIter<short>::type, cmp_fnptr<short>::type);
template void kerbal::algorithm::sort(RasIter<short>::type, RasIter<short>::type, cmp_fnptr<short>::type);
template void kerbal::algorithm::sort(BdrIter<short>::type, BdrIter<short>::type, cmp_fnptr<short>::type);
template void kerbal::algorithm::sort(FwlIter<short>::type, FwlIter<short>::type, cmp_fnptr<short>::type);
template void kerbal::algorithm::sort(FwdIter<short>::type, FwdIter<short>::type, cmp_fnptr<short>::type);

template void kerbal::algorithm::sort(CtgIter<short>::type, CtgIter<short>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(RasIter<short>::type, RasIter<short>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(BdrIter<short>::type, BdrIter<short>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(FwlIter<short>::type, FwlIter<short>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(FwdIter<short>::type, FwdIter<short>::type, kerbal::compare::less<>);

template void kerbal::algorithm::sort(CtgIter<short>::type, CtgIter<short>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(RasIter<short>::type, RasIter<short>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(BdrIter<short>::type, BdrIter<short>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(FwlIter<short>::type, FwlIter<short>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(FwdIter<short>::type, FwdIter<short>::type, kerbal::compare::greater<>);

template void kerbal::algorithm::sort(CtgIter<int>::type, CtgIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort(RasIter<int>::type, RasIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort(BdrIter<int>::type, BdrIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort(FwlIter<int>::type, FwlIter<int>::type, cmp_fnptr<int>::type);
template void kerbal::algorithm::sort(FwdIter<int>::type, FwdIter<int>::type, cmp_fnptr<int>::type);

template void kerbal::algorithm::sort(CtgIter<int>::type, CtgIter<int>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(RasIter<int>::type, RasIter<int>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(BdrIter<int>::type, BdrIter<int>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(FwlIter<int>::type, FwlIter<int>::type, kerbal::compare::less<>);
template void kerbal::algorithm::sort(FwdIter<int>::type, FwdIter<int>::type, kerbal::compare::less<>);

template void kerbal::algorithm::sort(CtgIter<int>::type, CtgIter<int>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(RasIter<int>::type, RasIter<int>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(BdrIter<int>::type, BdrIter<int>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(FwlIter<int>::type, FwlIter<int>::type, kerbal::compare::greater<>);
template void kerbal::algorithm::sort(FwdIter<int>::type, FwdIter<int>::type, kerbal::compare::greater<>);

template void kerbal::algorithm::sort(CtgIter<std::string>::type, CtgIter<std::string>::type, cmp_fnptr<std::string>::type);
template void kerbal::algorithm::sort(RasIter<std::string>::type, RasIter<std::string>::type, cmp_fnptr<std::string>::type);
template void kerbal::algorithm::sort(BdrIter<std::string>::type, BdrIter<std::string>::type, cmp_fnptr<std::string>::type);
template void kerbal::algorithm::sort(FwlIter<std::string>::type, FwlIter<std::string>::type, cmp_fnptr<std::string>::type);
template void kerbal::algorithm::sort(FwdIter<std::string>::type, FwdIter<std::string>::type, cmp_fnptr<std::string>::type);
