/**
 * @file       any.inst.cpp
 * @brief
 * @date       2021-10-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/any/any.hpp>

#include <kerbal/container/array.hpp>


namespace ka = kerbal::any;

typedef kerbal::container::array<int, 10> arr_i_10;

template class ka::basic_any<>;
template ka::basic_any<>::basic_any(kerbal::utility::in_place_type_t<int>, const int &);
template ka::basic_any<>::basic_any(kerbal::utility::in_place_type_t<arr_i_10>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void ka::basic_any<>::emplace<int>(const int &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void ka::basic_any<>::emplace<arr_i_10>();

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	include <kerbal/config/compiler_private.hpp>
#	if !KERBAL_GNU_VERSION_MEETS(5, 0, 0)
#		define KTEST_ANY_REF_QUALIFIER_MEMFUN_ICE 1
#	endif
#endif

#ifndef KTEST_ANY_REF_QUALIFIER_MEMFUN_ICE

template KERBAL_MSVC_TMPINST_CONSTEXPR20
int ka::basic_any<>::get<int>() KERBAL_REFERENCE_OVERLOAD_TAG;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
int & ka::basic_any<>::get<int &>() KERBAL_REFERENCE_OVERLOAD_TAG;

#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
int ka::basic_any<>::get<int>() KERBAL_CONST_REFERENCE_OVERLOAD_TAG;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
const int & ka::basic_any<>::get<const int &>() KERBAL_CONST_REFERENCE_OVERLOAD_TAG;

#ifndef KTEST_ANY_REF_QUALIFIER_MEMFUN_ICE

template KERBAL_MSVC_TMPINST_CONSTEXPR20
arr_i_10 ka::basic_any<>::get<arr_i_10>() KERBAL_REFERENCE_OVERLOAD_TAG;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
arr_i_10 & ka::basic_any<>::get<arr_i_10 &>() KERBAL_REFERENCE_OVERLOAD_TAG;

#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
arr_i_10 ka::basic_any<>::get<arr_i_10>() KERBAL_CONST_REFERENCE_OVERLOAD_TAG;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
const arr_i_10 & ka::basic_any<>::get<const arr_i_10 &>() KERBAL_CONST_REFERENCE_OVERLOAD_TAG;


