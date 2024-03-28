/**
 * @file       array.a2d.inst.cpp
 * @brief
 * @date       2024-03-28
 * @author     Peter
 * @ori        array.inst.cpp 2020-09-17
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/container/array.hpp>


template class kerbal::container::array<int[4][4], 4>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kerbal::container::array<int[4][4], 4>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kerbal::container::array<int[4][4], 4>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kerbal::container::array<int[4][4], 4>::assign(const_reverse_iterator, const_reverse_iterator);
