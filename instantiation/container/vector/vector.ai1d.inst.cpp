/**
 * @file       vector.ai1d.inst.cpp
 * @brief
 * @date       2024-03-28
 * @author     Peter
 * @ori        vector.inst.cpp 2021-08-01
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/container/vector.hpp>
#include <kerbal/memory/allocator/default_allocator.hpp>


namespace kc = kerbal::container;
namespace km = kerbal::memory;


// std::allocator doesn't support array

template class kc::vector<int[8], km::default_allocator<int[8]> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::vector(const_reverse_iterator, const_reverse_iterator, int);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::iterator
kc::vector<int[8], km::default_allocator<int[8]> >::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::iterator
kc::vector<int[8], km::default_allocator<int[8]> >::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8], km::default_allocator<int[8]> >::reference
kc::vector<int[8], km::default_allocator<int[8]> >::emplace_back(const_reference);
