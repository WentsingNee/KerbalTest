/**
 * @file       binary_search.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/iterator/iterators.hpp>

#include <kerbal/algorithm/binary_search.hpp>

template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};

#include <string>


template CtgIter<int>::type kerbal::algorithm::lower_bound(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::lower_bound(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::lower_bound(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);


template CtgIter<std::string>::type kerbal::algorithm::lower_bound(CtgIter<std::string>::type, CtgIter<std::string>::type, const char * const &);
template RasIter<std::string>::type kerbal::algorithm::lower_bound(RasIter<std::string>::type, RasIter<std::string>::type, const char * const &);
template BdrIter<std::string>::type kerbal::algorithm::lower_bound(BdrIter<std::string>::type, BdrIter<std::string>::type, const char * const &);
template FwlIter<std::string>::type kerbal::algorithm::lower_bound(FwlIter<std::string>::type, FwlIter<std::string>::type, const char * const &);
template FwdIter<std::string>::type kerbal::algorithm::lower_bound(FwdIter<std::string>::type, FwdIter<std::string>::type, const char * const &);


template CtgIter<int>::type kerbal::algorithm::lower_bound_backward(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound_backward(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound_backward(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);


template CtgIter<int>::type kerbal::algorithm::upper_bound(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::upper_bound(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::upper_bound(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);


template CtgIter<std::string>::type kerbal::algorithm::upper_bound(CtgIter<std::string>::type, CtgIter<std::string>::type, const char * const &);
template RasIter<std::string>::type kerbal::algorithm::upper_bound(RasIter<std::string>::type, RasIter<std::string>::type, const char * const &);
template BdrIter<std::string>::type kerbal::algorithm::upper_bound(BdrIter<std::string>::type, BdrIter<std::string>::type, const char * const &);
template FwlIter<std::string>::type kerbal::algorithm::upper_bound(FwlIter<std::string>::type, FwlIter<std::string>::type, const char * const &);
template FwdIter<std::string>::type kerbal::algorithm::upper_bound(FwdIter<std::string>::type, FwdIter<std::string>::type, const char * const &);


template CtgIter<int>::type kerbal::algorithm::upper_bound_backward(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound_backward(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound_backward(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);


template kerbal::utility::compressed_pair<CtgIter<int>::type, CtgIter<int>::type> kerbal::algorithm::equal_range(CtgIter<int>::type, CtgIter<int>::type, int const&, cmp_fnptr<int>::type);
template kerbal::utility::compressed_pair<RasIter<int>::type, RasIter<int>::type> kerbal::algorithm::equal_range(RasIter<int>::type, RasIter<int>::type, int const&, cmp_fnptr<int>::type);
template kerbal::utility::compressed_pair<BdrIter<int>::type, BdrIter<int>::type> kerbal::algorithm::equal_range(BdrIter<int>::type, BdrIter<int>::type, int const&, cmp_fnptr<int>::type);
template kerbal::utility::compressed_pair<FwlIter<int>::type, FwlIter<int>::type> kerbal::algorithm::equal_range(FwlIter<int>::type, FwlIter<int>::type, int const&, cmp_fnptr<int>::type);
template kerbal::utility::compressed_pair<FwdIter<int>::type, FwdIter<int>::type> kerbal::algorithm::equal_range(FwdIter<int>::type, FwdIter<int>::type, int const&, cmp_fnptr<int>::type);


template kerbal::utility::compressed_pair<CtgIter<std::string>::type, CtgIter<std::string>::type>
kerbal::algorithm::equal_range(CtgIter<std::string>::type, CtgIter<std::string>::type, const char * const &);

template kerbal::utility::compressed_pair<RasIter<std::string>::type, RasIter<std::string>::type>
kerbal::algorithm::equal_range(RasIter<std::string>::type, RasIter<std::string>::type, const char * const &);

template kerbal::utility::compressed_pair<BdrIter<std::string>::type, BdrIter<std::string>::type>
kerbal::algorithm::equal_range(BdrIter<std::string>::type, BdrIter<std::string>::type, const char * const &);

template kerbal::utility::compressed_pair<FwlIter<std::string>::type, FwlIter<std::string>::type>
kerbal::algorithm::equal_range(FwlIter<std::string>::type, FwlIter<std::string>::type, const char * const &);

template kerbal::utility::compressed_pair<FwdIter<std::string>::type, FwdIter<std::string>::type>
kerbal::algorithm::equal_range(FwdIter<std::string>::type, FwdIter<std::string>::type, const char * const &);


template CtgIter<int>::type kerbal::algorithm::lower_bound_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::lower_bound_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::lower_bound_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::lower_bound_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::lower_bound_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);


template CtgIter<int>::type kerbal::algorithm::upper_bound_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template RasIter<int>::type kerbal::algorithm::upper_bound_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template BdrIter<int>::type kerbal::algorithm::upper_bound_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template FwlIter<int>::type kerbal::algorithm::upper_bound_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template FwdIter<int>::type kerbal::algorithm::upper_bound_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);


template bool kerbal::algorithm::binary_search(CtgIter<int>::type, CtgIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(RasIter<int>::type, RasIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(BdrIter<int>::type, BdrIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwlIter<int>::type, FwlIter<int>::type, const int&, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search(FwdIter<int>::type, FwdIter<int>::type, const int&, cmp_fnptr<int>::type);


template bool kerbal::algorithm::binary_search(CtgIter<std::string>::type, CtgIter<std::string>::type, const char * const &);
template bool kerbal::algorithm::binary_search(RasIter<std::string>::type, RasIter<std::string>::type, const char * const &);
template bool kerbal::algorithm::binary_search(BdrIter<std::string>::type, BdrIter<std::string>::type, const char * const &);
template bool kerbal::algorithm::binary_search(FwlIter<std::string>::type, FwlIter<std::string>::type, const char * const &);
template bool kerbal::algorithm::binary_search(FwdIter<std::string>::type, FwdIter<std::string>::type, const char * const &);


template bool kerbal::algorithm::binary_search_hint(CtgIter<int>::type, CtgIter<int>::type, const int&, CtgIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(RasIter<int>::type, RasIter<int>::type, const int&, RasIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(BdrIter<int>::type, BdrIter<int>::type, const int&, BdrIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwlIter<int>::type, FwlIter<int>::type, const int&, FwlIter<int>::type, cmp_fnptr<int>::type);
template bool kerbal::algorithm::binary_search_hint(FwdIter<int>::type, FwdIter<int>::type, const int&, FwdIter<int>::type, cmp_fnptr<int>::type);
